#include "requestmapper.h"
#include "GLOBALS.h"

RequestMapper::RequestMapper(QObject *parent):HttpRequestHandler(parent)
{

}

void RequestMapper::service(HttpRequest &request, HttpResponse &response)
{
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if(path == "/stat-api"){
        homePageController.service(request,response);
    }else if(path.startsWith("/dashboard")){
        staticFileController->service(request,response);
    }else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.");
    }
}
