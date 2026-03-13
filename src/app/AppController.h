#pragma once

#include <QObject>
#include <QString>
#include <QStringList>

#include "../data/DataStore.h"
#include "../data/ExerciseRepository.h"
#include "../data/MuscleStats.h"

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString selectedMuscleId READ selectedMuscleId NOTIFY selectedMuscleChanged)
    Q_PROPERTY(QString muscleName READ muscleName NOTIFY selectedMuscleChanged)
    Q_PROPERTY(QString muscleDescription READ muscleDescription NOTIFY selectedMuscleChanged)
    Q_PROPERTY(QStringList exerciseList READ exerciseList NOTIFY selectedMuscleChanged)

    Q_PROPERTY(int totalSelections READ totalSelections NOTIFY statsChanged)
    Q_PROPERTY(QString mostPopularMuscle READ mostPopularMuscle NOTIFY statsChanged)
    Q_PROPERTY(int currentMuscleClicks READ currentMuscleClicks NOTIFY statsChanged)
    Q_PROPERTY(QStringList recentSelections READ recentSelections NOTIFY statsChanged)

public:
    explicit AppController(QObject *parent = nullptr);

    Q_INVOKABLE void selectMuscle(const QString& id);

    QString selectedMuscleId() const;
    QString muscleName() const;
    QString muscleDescription() const;
    QStringList exerciseList() const;

    int totalSelections() const;
    QString mostPopularMuscle() const;
    int currentMuscleClicks() const;
    QStringList recentSelections() const;

signals:
    void selectedMuscleChanged();
    void statsChanged();

private:
    QString selectedMuscleId_;
    DataStore dataStore_;
    ExerciseRepository exerciseRepository_;
    MuscleStats stats_;
};
