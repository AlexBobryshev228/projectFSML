#pragma once

#include <QObject>
#include <QStringList>

#include "../data/DataStore.h"
#include "../data/ExerciseRepository.h"
#include "../workout/WorkoutPlanner.h"

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString selectedMuscleId READ selectedMuscleId NOTIFY selectedMuscleIdChanged)
    Q_PROPERTY(QString muscleName READ muscleName NOTIFY muscleNameChanged)
    Q_PROPERTY(QString muscleDescription READ muscleDescription NOTIFY muscleDescriptionChanged)
    Q_PROPERTY(QStringList exercises READ exercises NOTIFY exercisesChanged)

    Q_PROPERTY(QString workoutTitle READ workoutTitle NOTIFY workoutPlanChanged)
    Q_PROPERTY(QStringList workoutSteps READ workoutSteps NOTIFY workoutPlanChanged)

public:
    explicit AppController();

    QString selectedMuscleId() const
    {
        return selectedMuscleId_;
    }

    QString muscleName() const
    {
        return muscleName_;
    }

    QString muscleDescription() const
    {
        return muscleDescription_;
    }

    QStringList exercises() const
    {
        return exercises_;
    }

    QString workoutTitle() const
    {
        return workoutTitle_;
    }

    QStringList workoutSteps() const
    {
        return workoutSteps_;
    }

    Q_INVOKABLE void selectMuscle(const QString& id);
    Q_INVOKABLE void buildWorkoutPlan();
    Q_INVOKABLE void buildStrengthPlan();
    Q_INVOKABLE void buildEndurancePlan();

signals:
    void selectedMuscleIdChanged();
    void muscleNameChanged();
    void muscleDescriptionChanged();
    void exercisesChanged();
    void workoutPlanChanged();

private:
    void applySelection(const QString& id);
    void buildPlanWithGoal(const WorkoutGoal& goal);

    ExerciseRepository exerciseRepo_;
    WorkoutPlanner planner_;
    DataStore store_;

    QString selectedMuscleId_;
    QString muscleName_;
    QString muscleDescription_;
    QStringList exercises_;

    QString workoutTitle_;
    QStringList workoutSteps_;
};
