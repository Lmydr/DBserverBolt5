#ifndef HOMEPAGECONTROLLER_H
#define HOMEPAGECONTROLLER_H

#include <httprequesthandler.h>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace stefanfrings;

class HomePageController : public HttpRequestHandler
{
public:
    HomePageController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    void init();

private:
    QSqlDatabase db;
};

#endif // HOMEPAGECONTROLLER_H
