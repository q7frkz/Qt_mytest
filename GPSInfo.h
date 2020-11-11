#ifndef GPSINFO_H
#define GPSINFO_H

#include <QString>

#include "GPSInfo.h"

class GPSInfo
{
    public:
        GPSInfo() {};
        ~GPSInfo() {/*if (next) delete next;*/};
        void setInfo(QString &);
        const QString &getInfo();
        GPSInfo *next = nullptr;
        GPSInfo *prev = nullptr;
    private:
        QString _info;
};


#endif //GPSINFO_H
