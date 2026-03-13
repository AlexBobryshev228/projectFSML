#include "AppController.h"

AppController::AppController(QObject *parent)
    : QObject(parent)
{
}

void AppController::selectMuscle(const QString& id)
{
    if (id.isEmpty())
        return;

    selectedMuscleId_ = id;
    stats_.registerSelection(id);

    emit selectedMuscleChanged();
    emit statsChanged();
}

QString AppController::selectedMuscleId() const
{
    return selectedMuscleId_;
}

QString AppController::muscleName() const
{
    if (selectedMuscleId_.isEmpty())
        return "Select a muscle";

    return dataStore_.muscleName(selectedMuscleId_);
}

QString AppController::muscleDescription() const
{
    if (selectedMuscleId_.isEmpty())
        return "Click on a muscle zone to see information.";

    return dataStore_.muscleDescription(selectedMuscleId_);
}

QStringList AppController::exerciseList() const
{
    if (selectedMuscleId_.isEmpty())
        return {};

    return exerciseRepository_.exerciseNamesForMuscle(selectedMuscleId_);
}

int AppController::totalSelections() const
{
    return stats_.totalSelections();
}

QString AppController::mostPopularMuscle() const
{
    const QString id = stats_.mostPopularMuscle();
    if (id.isEmpty())
        return "No data";

    return dataStore_.muscleName(id);
}

int AppController::currentMuscleClicks() const
{
    if (selectedMuscleId_.isEmpty())
        return 0;

    return stats_.selectionCount(selectedMuscleId_);
}

QStringList AppController::recentSelections() const
{
    QStringList ids = stats_.recentSelections();
    QStringList names;

    for (const QString& id : ids)
    {
        names.append(dataStore_.muscleName(id));
    }

    return names;
}
