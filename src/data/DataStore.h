#pragma once

#include <QString>
#include <QStringList>

class DataStore {
public:
    QString muscleName(const QString& id) const;
    QString muscleDescription(const QString& id) const;

};
