#pragma once

#include <QString>
#include "MuscleInfo.h"
class DataStore
{
public:
    MuscleInfo muscleInfo(const QString& id) const;
    QStringList allMuscleIds() const;
    QString muscleName(const QString& id) const;
    QString muscleDescription(const QString& id) const;
};
