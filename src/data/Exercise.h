#pragma once

#include <QString>

class Exercise
{
private:
    QString muscleId;
    QString name;
    QString difficulty;
    QString equipment;

public:
    Exercise(const QString& muscleId,
             const QString& name,
             const QString& difficulty,
             const QString& equipment)
        : muscleId(muscleId),
        name(name),
        difficulty(difficulty),
        equipment(equipment)
    {}

    QString getMuscleId() const { return muscleId; }
    QString getName() const { return name; }
    QString getDifficulty() const { return difficulty; }
    QString getEquipment() const { return equipment; }
};
