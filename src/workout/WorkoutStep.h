#pragma once

#include <QString>
#include <memory>
#include "../data/Exercise.h"

class WorkoutStep
{
public:
    virtual ~WorkoutStep() = default;
    virtual QString displayText() const = 0;
};

class ExerciseStep : public WorkoutStep
{
public:
    ExerciseStep(std::shared_ptr<Exercise> exercise, int sets, int reps)
        : exercise_(std::move(exercise)), sets_(sets), reps_(reps) {}

    QString displayText() const override
    {
        return QString("%1 — %2x%3")
            .arg(exercise_ ? exercise_->name : "Unknown exercise")
            .arg(sets_)
            .arg(reps_);
    }

private:
    std::shared_ptr<Exercise> exercise_;
    int sets_ = 0;
    int reps_ = 0;
};

class RestStep : public WorkoutStep
{
public:
    explicit RestStep(int seconds) : seconds_(seconds) {}

    QString displayText() const override
    {
        return QString("Rest — %1 sec").arg(seconds_);
    }

private:
    int seconds_ = 0;
};
