#include "AppController.h"
AppController::AppController(){

}
void AppController::selectMuscle(const QString& id){
    applySelection(id);
}
void AppController::applySelection(const QString& id){
    if (id == selectedMuscleId_) return;
    //просто из нашего стора закидываем значения по айди
    selectedMuscleId_ = id;
    muscleName_ = store_.muscleName(id);
    muscleDescription_ = store_.muscleDescription(id);
    exercises_ = store_.exerciseNamesForMuscle(id);
    emit selectedMuscleIdChanged();
    emit muscleNameChanged();
    emit muscleDescriptionChanged();
    emit exercisesChanged();
}

