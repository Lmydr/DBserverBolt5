#include "db.h"
#include <QDateTime>
#include <QSqlError>
#include <QDebug>
#include <QDataStream>

DB::DB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DashboardDB.sqlite");
    if(!db.open()){
        qDebug()<<"Error! db was not opened";
    }else{
        QSqlQuery query = db.exec();

        if(!query.exec("CREATE TABLE IF NOT EXISTS " TABLE_NAME "("
                       "speed        INTEGER NOT NULL,"
                       "cpu          REAL NOT NULL,"
                       "mem          INTEGER NOT NULL,"
                       "dec_count    INTEGER NOT NULL,"
                       "data         TEXT NOT NULL"
                       ")"))
        {
            qDebug()<<"Error where create a table";
            qDebug()<<query.lastError().text();
        }
    }
}

void DB::addDataToDB(dashboard_data_t data)
{

    QString values = QString("%1,%2,%3,%4,' %5 ')")
            .arg(QString::number(data.speed),
                 QString::number(data.cpu),
                 QString::number(data.mem),
                 QString::number(data.dec_count),
                 QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz"));

    QSqlQuery query = db.exec();
    if(!query.exec("INSERT INTO " TABLE_NAME " ("
               "speed,"
               "cpu,"
               "mem,"
               "dec_count,"
               "data"
               ")"
               "VALUES ("+values))
    {
        qDebug()<<query.lastError().text();
    };
}

