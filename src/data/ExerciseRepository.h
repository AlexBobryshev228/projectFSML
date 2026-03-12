#include "ExerciseRepository.h"

#include <optional>
#include <stdexcept>
#include <variant>
#include <memory>

constexpr const char* EASY = "Easy";
constexpr const char* MEDIUM = "Medium";
constexpr const char* HARD = "Hard";

using EquipmentType = std::variant<QString, int>;

ExerciseRepository::ExerciseRepository()
{
    exercises.append(
        Exercise("biceps", "Barbell Curl", MEDIUM, "Barbell")
        );
    exercises.append(
        Exercise("biceps", "Hammer Curl", EASY, "Dumbbells")
        );
    exercises.append(
        Exercise("biceps", "Concentration Curl", MEDIUM, "Dumbbells")
        );

    exercises.append(
        Exercise("chest", "Bench Press", HARD, "Barbell")
        );
    exercises.append(
        Exercise("chest", "Push-ups", EASY, "Bodyweight")
        );
    exercises.append(
        Exercise("chest", "Incline Dumbbell Press", MEDIUM, "Dumbbells")
        );

    exercises.append(
        Exercise("triceps", "Tricep Dips", MEDIUM, "Bodyweight")
        );
    exercises.append(
        Exercise("triceps", "Overhead Tricep Extension", MEDIUM, "Dumbbells")
        );

    exercises.append(
        Exercise("legs", "Squats", HARD, "Barbell")
        );
    exercises.append(
        Exercise("legs", "Lunges", MEDIUM, "Bodyweight")
        );

    exercises.append(
        Exercise("shoulders", "Shoulder Press", MEDIUM, "Dumbbells")
        );
    exercises.append(
        Exercise("shoulders", "Lateral Raise", EASY, "Dumbbells")
        );

    exercises.append(
        Exercise("abs", "Crunches", EASY, "Bodyweight")
        );
    exercises.append(
        Exercise("abs", "Leg Raises", MEDIUM, "Bodyweight")
        );

    exercises.append(
        Exercise("quads", "Front Squat", HARD, "Barbell")
        );
    exercises.append(
        Exercise("quads", "Leg Extension", MEDIUM, "Machine")
        );

    exercises.append(
        Exercise("calves", "Standing Calf Raise", EASY, "Machine")
        );
    exercises.append(
        Exercise("calves", "Seated Calf Raise", MEDIUM, "Machine")
        );

    exercises.append(
        Exercise("lats", "Pull-Ups", HARD, "Bodyweight")
        );
    exercises.append(
        Exercise("lats", "Lat Pulldown", MEDIUM, "Machine")
        );
}

void ExerciseRepository::addExercise(const Exercise& e)
{
    exercises.append(e);
}

QStringList ExerciseRepository::exerciseNamesForMuscle(const QString& muscleId) const
{
    QStringList result;

    for (const auto& e : exercises)
    {
        if (e.muscleId == muscleId)
        {
            result.append(e.name);
        }
    }

    return result;
}

QStringList ExerciseRepository::allMuscleIds() const
{
    QStringList result;

    for (const auto& e : exercises)
    {
        if (!result.contains(e.muscleId))
        {
            result.append(e.muscleId);
        }
    }

    return result;
}

std::optional<Exercise> ExerciseRepository::findExerciseByName(const QString& name) const
{
    for (const auto& e : exercises)
    {
        if (e.name == name)
        {
            return e;
        }
    }

    return std::nullopt;
}

Exercise ExerciseRepository::getExerciseOrThrow(const QString& name) const
{
    for (const auto& e : exercises)
    {
        if (e.name == name)
        {
            return e;
        }
    }

    throw std::runtime_error("Exercise not found");
}

std::unique_ptr<Exercise> ExerciseRepository::createExerciseCopy(const QString& name) const
{
    for (const auto& e : exercises)
    {
        if (e.name == name)
        {
            return std::make_unique<Exercise>(e);
        }
    }

    return nullptr;
}

std::shared_ptr<Exercise> ExerciseRepository::getSharedExercise(const QString& name) const
{
    for (const auto& e : exercises)
    {
        if (e.name == name)
        {
            return std::make_shared<Exercise>(e);
        }
    }

    return nullptr;
}
