#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QString>
#include "httplistener.h"
#include "httprequesthandler.h"
#include "requestmapper.h"

#include "GLOBALS.h"

StaticFileController* staticFileController;

using namespace stefanfrings;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings* listenerSettings = new QSettings("../TestWebServerApp/etc/testwebapp.ini",QSettings::IniFormat,&a);
    listenerSettings->beginGroup("listener");

    QSettings* fileSettings=new QSettings("../TestWebServerApp/etc/testwebapp.ini",QSettings::IniFormat,&a);
    fileSettings->beginGroup("files");
    staticFileController=new StaticFileController(fileSettings,&a);

    new HttpListener(listenerSettings, new RequestMapper(&a), &a);

    return a.exec();
}
