#ifndef DB_H
#define DB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "structs.h"

#define TABLE_NAME "resursesTable"

class DB : public QObject
{
    Q_OBJECT
public:
    explicit DB(QObject *parent = nullptr);


public slots:
    void addDataToDB(dashboard_data_t);

signals:

private:
    QSqlDatabase db;

};

#endif // DB_H
