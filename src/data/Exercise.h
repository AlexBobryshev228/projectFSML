#pragma once

#include <QString>

struct Exercise
{
    QString muscleId;
    QString name;
    QString difficulty;
    QString equipment;

    Exercise(QString muscleId,
             QString name,
             QString difficulty,
             QString equipment)
        : muscleId(muscleId),
        name(name),
        difficulty(difficulty),
        equipment(equipment)
    {}
};