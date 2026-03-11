#include "ExerciseRepository.h"

ExerciseRepository::ExerciseRepository()
{

    exercises.append(
        Exercise("biceps", "Barbell Curl", "Medium", "Barbell")
        );

    exercises.append(
        Exercise("biceps", "Hammer Curl", "Easy", "Dumbbells")
        );

    exercises.append(
        Exercise("biceps", "Concentration Curl", "Medium", "Dumbbells")
        );

    exercises.append(
        Exercise("chest", "Bench Press", "Hard", "Barbell")
        );

    exercises.append(
        Exercise("chest", "Push-ups", "Easy", "Bodyweight")
        );

    exercises.append(
        Exercise("chest", "Incline Dumbbell Press", "Medium", "Dumbbells")
        );

    exercises.append(
        Exercise("triceps", "Tricep Dips", "Medium", "Bodyweight")
        );

    exercises.append(
        Exercise("triceps", "Overhead Tricep Extension", "Medium", "Dumbbells")
        );

    exercises.append(
        Exercise("legs", "Squats", "Hard", "Barbell")
        );

    exercises.append(
        Exercise("legs", "Lunges", "Medium", "Bodyweight")
        );

    exercises.append(
        Exercise("shoulders", "Shoulder Press", "Medium", "Dumbbells")
        );

    exercises.append(
        Exercise("shoulders", "Lateral Raise", "Easy", "Dumbbells")
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
