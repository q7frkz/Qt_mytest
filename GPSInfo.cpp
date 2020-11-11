#include "GPSInfo.h"

void GPSInfo::setInfo(QString &info)
{
    _info = info;
}

const QString &GPSInfo::getInfo()
{
    return _info;
}