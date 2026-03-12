#pragma once

#include <QVector>
#include <QStringList>
#include <optional>
#include <variant>
#include <memory>

#include "Exercise.h"

class ExerciseRepository
{
public:
    ExerciseRepository();
    QStringList exerciseNamesForMuscle(const QString& muscleId) const;
    void addExercise(const Exercise& e);

    QStringList allMuscleIds() const;

    std::optional<Exercise> findExerciseByName(const QString& name) const;
    Exercise getExerciseOrThrow(const QString& name) const;
    std::unique_ptr<Exercise> createExerciseCopy(const QString& name) const;
    std::shared_ptr<Exercise> getSharedExercise(const QString& name) const;

private:
    QVector<Exercise> exercises;
};