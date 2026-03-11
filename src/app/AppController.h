#pragma once

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

public:
    explicit AppController();

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
    Q_INVOKABLE void selectMuscle(const QString& id); //делаем чтобы qml видел нашу функцию
signals: //сигналы что поменялось
    void selectedMuscleIdChanged();
    void muscleNameChanged();
    void muscleDescriptionChanged();
    void exercisesChanged();

private:
    void applySelection(const QString& id);
    ExerciseRepository exerciseRepo_;
    DataStore store_; // наш источник
    QString selectedMuscleId_;  // мышца которую мы выбрали
    QString muscleName_;        // имя выбранной мышцы
    QString muscleDescription_; // описание выбранной мышцы
    QStringList exercises_;     // список упражнений выбранной мышцы
};
