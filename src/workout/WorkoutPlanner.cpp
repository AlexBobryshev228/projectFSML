#include "WorkoutPlanner.h"
#include <memory>
#include <type_traits>

WorkoutPlanner::WorkoutPlanner(const ExerciseRepository& repository)
    : repository_(repository)
{
}

constexpr int STRENGTH_SETS = 4;
constexpr int STRENGTH_REPS = 6;
constexpr int STRENGTH_REST = 120;

constexpr int HYPERTROPHY_SETS = 3;
constexpr int HYPERTROPHY_REPS = 10;
constexpr int HYPERTROPHY_REST = 75;

constexpr int ENDURANCE_SETS = 2;
constexpr int ENDURANCE_REPS = 18;
constexpr int ENDURANCE_REST = 45;

int WorkoutPlanner::setsForGoal(const WorkoutGoal& goal) const
{
    return std::visit([](const auto& g) -> int {
        using T = std::decay_t<decltype(g)>;
        if constexpr (std::is_same_v<T, StrengthGoal>) return STRENGTH_SETS;
        if constexpr (std::is_same_v<T, HypertrophyGoal>) return HYPERTROPHY_SETS;
        return ENDURANCE_SETS;
    }, goal);
}

int WorkoutPlanner::repsForGoal(const WorkoutGoal& goal) const
{
    return std::visit([](const auto& g) -> int {
        using T = std::decay_t<decltype(g)>;
        if constexpr (std::is_same_v<T, StrengthGoal>) return STRENGTH_REPS;
        if constexpr (std::is_same_v<T, HypertrophyGoal>) return HYPERTROPHY_REPS;
        return ENDURANCE_REPS;
    }, goal);
}

int WorkoutPlanner::restForGoal(const WorkoutGoal& goal) const
{
    return std::visit([](const auto& g) -> int {
        using T = std::decay_t<decltype(g)>;
        if constexpr (std::is_same_v<T, StrengthGoal>) return STRENGTH_REST;
        if constexpr (std::is_same_v<T, HypertrophyGoal>) return HYPERTROPHY_REST;
        return ENDURANCE_REST;
    }, goal);
}

QString WorkoutPlanner::titleFor(const QString& muscleId) const
{
    if (muscleId == "chest") return "Chest workout";
    if (muscleId == "biceps") return "Biceps workout";
    if (muscleId == "triceps") return "Triceps workout";
    if (muscleId == "shoulders") return "Shoulders workout";
    if (muscleId == "legs") return "Leg workout";
    if (muscleId == "abs") return "Abs workout";
    if (muscleId == "quads") return "Quads workout";
    if (muscleId == "calves") return "Calves workout";
    if (muscleId == "lats") return "Lats workout";
    return "Workout plan";
}

std::optional<WorkoutPlan> WorkoutPlanner::tryBuildPlan(const QString& muscleId,
                                                        const WorkoutGoal& goal) const
{
    const QStringList names = repository_.exerciseNamesForMuscle(muscleId);
    if (names.isEmpty())
    {
        return std::nullopt;
    }

    WorkoutPlan plan(titleFor(muscleId));

    const int sets = setsForGoal(goal);
    const int reps = repsForGoal(goal);
    const int rest = restForGoal(goal);

    for (const auto& name : names)
    {
        auto exercisePtr = repository_.getSharedExercise(name);
        if (!exercisePtr)
        {
            continue;
        }

        plan.addStep(std::make_unique<ExerciseStep>(exercisePtr, sets, reps));
        plan.addStep(std::make_unique<RestStep>(rest));
    }

    if (plan.empty())
    {
        return std::nullopt;
    }

    return std::move(plan);
}

WorkoutPlan WorkoutPlanner::buildPlanOrThrow(const QString& muscleId,
                                             const WorkoutGoal& goal) const
{
    auto plan = tryBuildPlan(muscleId, goal);
    if (!plan.has_value())
    {
        throw WorkoutPlannerException(
            QString("Cannot build workout plan for muscle id: %1")
                .arg(muscleId)
                .toStdString()
            );
    }

    return std::move(*plan);
}
