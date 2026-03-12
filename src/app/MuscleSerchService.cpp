#include "MuscleSearchService.h"

MuscleSearchService::MuscleSearchService()
{
    muscles_ = {
        {"biceps", "Biceps"},
        {"triceps", "Triceps"},
        {"chest", "Chest"},
        {"abs", "Abs"},
        {"lats", "Lats"},
        {"quads", "Quadriceps"},
        {"calves", "Calves"},
        {"back", "Back"}
    };
}

QStringList MuscleSearchService::search(const QString& query) const
{
    const QString q = query.trimmed();
    QStringList result;
    if (q.isEmpty()) {
        for (const auto& m : muscles_) result.append(m.id);
        return result;
    }

    for (const auto& m : muscles_) {
        if (m.id.contains(q, Qt::CaseInsensitive) ||
            m.name.contains(q, Qt::CaseInsensitive)) {
            result.append(m.id);
        }
    }

    return result;
}
