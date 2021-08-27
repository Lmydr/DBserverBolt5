#include "communicationms.h"
#include <QDataStream>
#include <QDateTime>

CommunicationMS::CommunicationMS(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(5000);
    connect(timer,&QTimer::timeout,this,&CommunicationMS::sendReqForData);


    socket = new QTcpSocket(this);
    socket->connectToHost("185.238.139.4",12012,QIODevice::ReadWrite);
    connect(socket,&QTcpSocket::connected,this,&CommunicationMS::connectDone);
    connect(socket,&QTcpSocket::readyRead,this,&CommunicationMS::readDataFromSocket);
    connect(socket,&QTcpSocket::errorOccurred,this,&CommunicationMS::errorFromSocket);

    db = new DB(this);
    connect(this,&CommunicationMS::addToDB,db,&DB::addDataToDB);
}

void CommunicationMS::connectDone()
{
    qDebug()<<"connected";
    socket->write(REQ.REQ_ALL_DATA);
    timer->start();
}

void CommunicationMS::readDataFromSocket()
{
    QByteArray buff = socket->readAll();
    dbData = dbData.parse(buff);
    qDebug()<<"CPU: "<<dbData.cpu
            <<"mem: "<<dbData.mem
            <<"Speed: "<<dbData.speed
            <<"dec_count "<<dbData.dec_count;
    emit addToDB(dbData);

}

void CommunicationMS::errorFromSocket()
{
    qDebug()<<socket->errorString();
}

void CommunicationMS::sendReqForData()
{
    socket->write(REQ.REQ_ALL_DATA);
}

