#pragma once
#include "MuscleSearchService.h"
#include <QObject>
#include <QStringList>
#include "../data/DataStore.h"
#include "../data/ExerciseRepository.h"

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString selectedMuscleId READ selectedMuscleId NOTIFY selectedMuscleIdChanged)
    Q_PROPERTY(QString muscleName READ muscleName NOTIFY muscleNameChanged)
    Q_PROPERTY(QString muscleDescription READ muscleDescription NOTIFY muscleDescriptionChanged)
    Q_PROPERTY(QStringList exercises READ exercises NOTIFY exercisesChanged)
    Q_PROPERTY(QStringList muscleResults READ muscleResults NOTIFY muscleResultsChanged)
public:
    explicit AppController();
    QStringList muscleResults() const { return muscleResults_; }
    QString selectedMuscleId() const {
        return selectedMuscleId_;
    }
    QString muscleName() const {
        return muscleName_;
    }
    QString muscleDescription() const {
        return muscleDescription_;
    }
    QStringList exercises() const {
        return exercises_;
    }
    Q_INVOKABLE void selectMuscle(const QString& id);
    Q_INVOKABLE void setMuscleSearchQuery(const QString& q);
signals:
    void selectedMuscleIdChanged();
    void muscleNameChanged();
    void muscleDescriptionChanged();
    void exercisesChanged();
    void muscleResultsChanged();
private:
    void applySelection(const QString& id);
    ExerciseRepository exerciseRepo_;
    DataStore store_;
    QString selectedMuscleId_;
    QString muscleName_;
    QString muscleDescription_;
    QStringList exercises_;
    MuscleSearchService searcher_;
    QStringList muscleResults_;
};
