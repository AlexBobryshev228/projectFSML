#pragma once

#include <QString>
#include "MuscleInfo.h"
QStringList allMuscleIds();
class DataStore
{
public:
    MuscleInfo muscleInfo(const QString& id) const;

    QString muscleName(const QString& id) const;
    QString muscleDescription(const QString& id) const;
};
