#include "homepagecontroller.h"
#include <QJsonDocument>
#include <QJsonArray>

HomePageController::HomePageController(QObject *parent):HttpRequestHandler(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../../DBbolt5/build-DBbolt5-Desktop_Qt_5_15_2_GCC_64bit-Debug/DashboardDB.sqlite");
    if(!db.open()){
        qDebug()<<"Error! db was not opened";
    }else qDebug()<<"DB OPEN!";
}

void HomePageController::service(HttpRequest &request, HttpResponse &response)
{

    QJsonArray jsonResponce;
    QSqlQuery q = db.exec();
    q.exec("SELECT * FROM resursesTable ORDER BY ROWID DESC LIMIT 1");
    if(q.next()){
        jsonResponce.append(q.value(0).toInt());
        jsonResponce.append(q.value(1).toDouble());
        jsonResponce.append(q.value(2).toInt());
        qDebug()<<"2.FROM BD:"<<q.value(2).toInt();
        jsonResponce.append(q.value(3).toInt());
    }else{
        jsonResponce.append(0);
        jsonResponce.append(0);
        jsonResponce.append(0);
        jsonResponce.append(0);
    }

    response.write(QJsonDocument(jsonResponce).toJson(),true);
}

void HomePageController::init()
{
}
