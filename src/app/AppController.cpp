#include "AppController.h"
AppController::AppController(){

}
void AppController::selectMuscle(const QString& id){
    applySelection(id);
}
void AppController::applySelection(const QString& id){
    if (id == selectedMuscleId_) return;
    selectedMuscleId_ = id;
    muscleName_ = store_.muscleName(id);
    muscleDescription_ = store_.muscleDescription(id);
    exercises_ = exerciseRepo_.exerciseNamesForMuscle(id);
    emit selectedMuscleIdChanged();
    emit muscleNameChanged();
    emit muscleDescriptionChanged();
    emit exercisesChanged();
}
void AppController::setMuscleSearchQuery(const QString& q)
{
    muscleResults_ = searcher_.search(q);
    emit muscleResultsChanged();
}

