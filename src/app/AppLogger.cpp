#include "AppLogger.h"
#include <QDebug>

void AppLogger::info(const QString& message) const
{
    qDebug().noquote() << "[INFO]" << message;
}
