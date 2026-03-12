#include "DataStore.h"

MuscleInfo DataStore::muscleInfo(const QString& id) const
{
    if (id == "biceps") {
        return MuscleInfo(
            "biceps",
            "Бицепс",
            "Сгибает руку в локте.",
            {"Barbell Curl", "Hammer Curl", "Concentration Curl"}
            );
    }

    if (id == "chest") {
        return MuscleInfo(
            "chest",
            "Грудные мышцы",
            "Участвуют в жимовых движениях и сведении рук.",
            {"Bench Press", "Incline Dumbbell Press", "Push-Ups"}
            );
    }

    if (id == "shoulders") {
        return MuscleInfo(
            "shoulders",
            "Плечи",
            "Поднимают и стабилизируют руки.",
            {"Overhead Press", "Lateral Raise", "Front Raise"}
            );
    }

    if (id == "legs") {
        return MuscleInfo(
            "legs",
            "Ноги",
            "Отвечают за приседания, выпады, ходьбу и бег.",
            {"Squat", "Lunge", "Leg Press"}
            );
    }

    if (id == "triceps") {
        return MuscleInfo(
            "triceps",
            "Трицепс",
            "Разгибает руку в локте.",
            {"Tricep Pushdown", "Dips", "Skull Crushers"}
            );
    }

    return MuscleInfo(
        id,
        "Неизвестно",
        "",
        {}
        );
}

QString DataStore::muscleName(const QString& id) const
{
    return muscleInfo(id).name();
}

QString DataStore::muscleDescription(const QString& id) const
{
    return muscleInfo(id).description();
}
