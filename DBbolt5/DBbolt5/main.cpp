#include <QCoreApplication>
#include <QDebug>
#include "communicationms.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"all right";
    CommunicationMS *cms;
    cms = new CommunicationMS();

    return a.exec();
}
