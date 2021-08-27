#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include <QObject>

#include "homepagecontroller.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler
{
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);

private:
    HomePageController homePageController;
};

#endif // REQUESTMAPPER_H
