#include "DataStore.h"

QString DataStore::muscleName(const QString& id) const
{
    if (id == "biceps") return "Бицепс";
    if (id == "chest")  return "Грудные мышцы";
    return "Неизвестно";
}

QString DataStore::muscleDescription(const QString& id) const
{
    if (id == "biceps") return "Сгибает руку в локте.";
    if (id == "chest")  return "Участвует в жимовых движениях и сведении рук.";
    return "";
}

QStringList DataStore::exerciseNamesForMuscle(const QString& muscleId) const
{
    if (muscleId == "biceps") {
        return {"Сгибания с гантелями", "Подтягивания обратным хватом", "Сгибания со штангой"};
    }
    if (muscleId == "chest") {
        return {"Отжимания", "Жим гантелей лёжа", "Жим штанги лёжа"};
    }
    return {};
}
