#pragma once

#include <QVector>
#include <QStringList>
#include "Exercise.h"

class ExerciseRepository
{
public:
    ExerciseRepository();

    QStringList exerciseNamesForMuscle(const QString& muscleId) const;

    void addExercise(const Exercise& e);

    QStringList allMuscleIds() const;

private:
    QVector<Exercise> exercises;
};