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

    exercises.append(Exercise("biceps", "Barbell Curl", MEDIUM, "Barbell"));
    exercises.append(Exercise("biceps", "Hammer Curl", EASY, "Dumbbells"));
    exercises.append(Exercise("biceps", "Concentration Curl", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("biceps", "Preacher Curl", MEDIUM, "Machine"));
    exercises.append(Exercise("biceps", "Cable Curl", EASY, "Cable Machine"));
    exercises.append(Exercise("biceps", "Incline Dumbbell Curl", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("biceps", "EZ Bar Curl", MEDIUM, "Barbell"));

    exercises.append(Exercise("chest", "Bench Press", HARD, "Barbell"));
    exercises.append(Exercise("chest", "Push-ups", EASY, "Bodyweight"));
    exercises.append(Exercise("chest", "Incline Dumbbell Press", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("chest", "Chest Fly", MEDIUM, "Machine"));
    exercises.append(Exercise("chest", "Decline Bench Press", HARD, "Barbell"));
    exercises.append(Exercise("chest", "Cable Crossover", MEDIUM, "Cable Machine"));
    exercises.append(Exercise("chest", "Chest Dips", HARD, "Bodyweight"));

    exercises.append(Exercise("triceps", "Tricep Dips", MEDIUM, "Bodyweight"));
    exercises.append(Exercise("triceps", "Overhead Tricep Extension", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("triceps", "Tricep Pushdown", MEDIUM, "Cable Machine"));
    exercises.append(Exercise("triceps", "Close Grip Bench Press", HARD, "Barbell"));
    exercises.append(Exercise("triceps", "Kickbacks", EASY, "Dumbbells"));
    exercises.append(Exercise("triceps", "Skull Crushers", HARD, "Barbell"));
    exercises.append(Exercise("triceps", "Diamond Push-ups", MEDIUM, "Bodyweight"));

    exercises.append(Exercise("quads", "Barbell Squat", HARD, "Barbell"));
    exercises.append(Exercise("quads", "Leg Press", MEDIUM, "Machine"));
    exercises.append(Exercise("quads", "Lunges", MEDIUM, "Bodyweight"));
    exercises.append(Exercise("quads", "Bulgarian Split Squat", HARD, "Dumbbells"));
    exercises.append(Exercise("quads", "Leg Extension", EASY, "Machine"));
    exercises.append(Exercise("quads", "Front Squat", HARD, "Barbell"));
    exercises.append(Exercise("quads", "Goblet Squat", MEDIUM, "Dumbbells"));

    exercises.append(Exercise("shoulders", "Shoulder Press", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("shoulders", "Lateral Raise", EASY, "Dumbbells"));
    exercises.append(Exercise("shoulders", "Front Raise", EASY, "Dumbbells"));
    exercises.append(Exercise("shoulders", "Arnold Press", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("shoulders", "Face Pull", MEDIUM, "Cable Machine"));
    exercises.append(Exercise("shoulders", "Upright Row", MEDIUM, "Barbell"));
    exercises.append(Exercise("shoulders", "Reverse Fly", MEDIUM, "Dumbbells"));

    exercises.append(Exercise("abs", "Crunches", EASY, "Bodyweight"));
    exercises.append(Exercise("abs", "Plank", EASY, "Bodyweight"));
    exercises.append(Exercise("abs", "Hanging Leg Raise", MEDIUM, "Pull-up Bar"));
    exercises.append(Exercise("abs", "Russian Twist", MEDIUM, "Bodyweight"));
    exercises.append(Exercise("abs", "Bicycle Crunch", EASY, "Bodyweight"));
    exercises.append(Exercise("abs", "Sit-ups", EASY, "Bodyweight"));
    exercises.append(Exercise("abs", "Mountain Climbers", MEDIUM, "Bodyweight"));

    exercises.append(Exercise("lats", "Pull-ups", HARD, "Pull-up Bar"));
    exercises.append(Exercise("lats", "Lat Pulldown", MEDIUM, "Machine"));
    exercises.append(Exercise("lats", "Single Arm Dumbbell Row", MEDIUM, "Dumbbells"));
    exercises.append(Exercise("lats", "Seated Cable Row", MEDIUM, "Cable Machine"));
    exercises.append(Exercise("lats", "Straight Arm Pulldown", EASY, "Cable Machine"));
    exercises.append(Exercise("lats", "T-Bar Row", HARD, "Barbell"));
    exercises.append(Exercise("lats", "Bent Over Row", HARD, "Barbell"));

    exercises.append(Exercise("calves", "Standing Calf Raise", EASY, "Bodyweight"));
    exercises.append(Exercise("calves", "Seated Calf Raise", MEDIUM, "Machine"));
    exercises.append(Exercise("calves", "Jump Rope", EASY, "Jump Rope"));
    exercises.append(Exercise("calves", "Donkey Calf Raise", MEDIUM, "Machine"));
    exercises.append(Exercise("calves", "Single Leg Calf Raise", MEDIUM, "Bodyweight"));
    exercises.append(Exercise("calves", "Box Jumps", HARD, "Bodyweight"));
    exercises.append(Exercise("calves", "Weighted Calf Raise", MEDIUM, "Barbell"));


}

void ExerciseRepository::addExercise(const Exercise& e){
    exercises.append(e);
}

QStringList ExerciseRepository::exerciseNamesForMuscle(const QString& muscleId) const{
    QStringList result;

    for (const auto& e : exercises){
        if (e.muscleId == muscleId){
            result.append(e.name);
        }
    }

    return result;
}

QStringList ExerciseRepository::allMuscleIds() const{
    QStringList result;

    for (const auto& e : exercises){
        if (!result.contains(e.muscleId)){
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
