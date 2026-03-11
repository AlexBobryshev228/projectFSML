#include "DataStore.h"

QString DataStore::muscleName(const QString& id) const
{
    if (id == "biceps") return "Бицепс";
    if (id == "chest")  return "Грудные мышцы";
    if (id == "d") return "михан жирный";
    return "Неизвестно";
}

QString DataStore::muscleDescription(const QString& id) const
{
    if (id == "biceps") return "Сгибает руку в локте.";
    if (id == "chest")  return "Участвует в жимовых движениях и сведении рук.";
    return "";
}


