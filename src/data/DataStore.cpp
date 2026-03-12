#include "DataStore.h"

QString DataStore::muscleName(const QString& id) const
{
    if (id == "biceps") return "Бицепс";
    if (id == "chest") return "Грудные мышцы";
    if (id == "triceps") return "Трицепс";
    if (id == "legs") return "Ноги";
    if (id == "shoulders") return "Плечи";

    return "Неизвестно";
}

QString DataStore::muscleDescription(const QString& id) const
{
    if (id == "biceps") return "Сгибает руку в локте.";
    if (id == "chest") return "Участвует в жимовых движениях и сведении рук.";
    if (id == "triceps") return "Разгибает руку в локте.";
    if (id == "legs") return "Отвечают за приседания, выпады, ходьбу и бег.";
    if (id == "shoulders") return "Поднимают и стабилизируют руки.";

    return "";
}
