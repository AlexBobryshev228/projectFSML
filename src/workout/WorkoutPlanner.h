#pragma once

#include <QString>
#include <optional>
#include <variant>
#include <stdexcept>
#include "../data/ExerciseRepository.h"
#include "WorkoutPlan.h"

struct StrengthGoal {};
struct HypertrophyGoal {};
struct EnduranceGoal {};

using WorkoutGoal = std::variant<StrengthGoal, HypertrophyGoal, EnduranceGoal>;

class WorkoutPlannerException : public std::runtime_error
{
public:
    explicit WorkoutPlannerException(const std::string& message)
        : std::runtime_error(message) {}
};

class WorkoutPlanner
{
public:
    explicit WorkoutPlanner(const ExerciseRepository& repository);

    std::optional<WorkoutPlan> tryBuildPlan(const QString& muscleId,
                                            const WorkoutGoal& goal) const;

    WorkoutPlan buildPlanOrThrow(const QString& muscleId,
                                 const WorkoutGoal& goal) const;

private:
    const ExerciseRepository& repository_;

    int setsForGoal(const WorkoutGoal& goal) const;
    int repsForGoal(const WorkoutGoal& goal) const;
    int restForGoal(const WorkoutGoal& goal) const;
    QString titleFor(const QString& muscleId) const;
};
