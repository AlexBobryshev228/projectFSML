#include "AppController.h"

AppController::AppController()
    : planner_(exerciseRepo_)
{
}

void AppController::selectMuscle(const QString& id)
{
    applySelection(id);
}

void AppController::applySelection(const QString& id)
{
    if (id == selectedMuscleId_)
        return;

    selectedMuscleId_ = id;
    muscleName_ = store_.muscleName(id);
    muscleDescription_ = store_.muscleDescription(id);
    exercises_ = exerciseRepo_.exerciseNamesForMuscle(id);

    workoutTitle_.clear();
    workoutSteps_.clear();

    emit selectedMuscleIdChanged();
    emit muscleNameChanged();
    emit muscleDescriptionChanged();
    emit exercisesChanged();
    emit workoutPlanChanged();
}

void AppController::buildWorkoutPlan()
{
    buildPlanWithGoal(HypertrophyGoal{});
}

void AppController::buildStrengthPlan()
{
    buildPlanWithGoal(StrengthGoal{});
}

void AppController::buildEndurancePlan()
{
    buildPlanWithGoal(EnduranceGoal{});
}

void AppController::buildPlanWithGoal(const WorkoutGoal& goal)
{
    if (selectedMuscleId_.isEmpty())
    {
        workoutTitle_ = "Workout plan unavailable";
        workoutSteps_ = { "Select a muscle first." };
        emit workoutPlanChanged();
        return;
    }

    try
    {
        WorkoutPlan plan = planner_.buildPlanOrThrow(selectedMuscleId_, goal);
        workoutTitle_ = plan.title();
        workoutSteps_ = plan.toDisplayList();
    }
    catch (const WorkoutPlannerException&)
    {
        workoutTitle_ = "Workout plan unavailable";
        workoutSteps_ = { "No exercises found for selected muscle." };
    }

    emit workoutPlanChanged();
}
