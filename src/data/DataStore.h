#pragma once
#include <QString>
#include <QStringList>
#include <QJsonObject>
class DataStore{
    bool loadFromResource(const QString& resourcePath);
    QString muscleName(const QString& id)const;
    QString muscleDescription(const QString& id) const;
    QStringList exerciseNamesForMuscle(const QString& muscleId) const;

private:
    QJsonObject root_;
};
