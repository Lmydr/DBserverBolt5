#ifndef COMMUNICATIONMS_H
#define COMMUNICATIONMS_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QTimer>
#include "db.h"
#include "structs.h"



class CommunicationMS : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationMS(QObject *parent = nullptr);

    struct REQUESTS{
        char REQ_ECHO       [1]{1};
        char REQ_TEST       [1]{2};

        char REQ_ALL_DATA   [1]{3};

        char REQ_SPEED      [1]{4};
        char REQ_STATUS     [1]{8};
        char REQ_MSG_CNT    [1]{16};
        char REQ_MEM        [1]{32};
        char REQ_CPU        [1]{68};
    };
/*
    struct dashboard_data_t{
        quint64 speed      = 0;
        double cpu         = 0;
        quint64 mem        = 0;
        quint64 dec_count  = 0;

        dashboard_data_t parse(QByteArray arr);
    };
    */

signals:
    void addToDB(dashboard_data_t);

private slots:
    void connectDone();
    void readDataFromSocket();
    void errorFromSocket();

    void sendReqForData();

private:
    QTcpSocket *socket;
    REQUESTS REQ;

    dashboard_data_t dbData;
    QTimer *timer;

    DB *db;


};

#endif // COMMUNICATIONMS_H
