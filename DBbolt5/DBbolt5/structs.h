#ifndef STRUCTS_H
#define STRUCTS_H

#include <QDataStream>

struct dashboard_data_t{
    quint64 speed      = 0;
    double cpu         = 0;
    quint64 mem        = 0;
    quint64 dec_count  = 0;

    dashboard_data_t parse(QByteArray arr){
        dashboard_data_t p;
        QDataStream ds(arr);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds >> p.speed >> p.cpu >> p.mem >>dec_count;
        return p;
    }
};

#endif // STRUCTS_H
