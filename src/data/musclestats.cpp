#include "MuscleStats.h"

void MuscleStats::registerSelection(const QString& muscleId)
{
    counts_[muscleId]++;
    totalSelections_++;

    recent_.removeAll(muscleId);
    recent_.prepend(muscleId);

    while (recent_.size() > 5)
        recent_.removeLast();
}

int MuscleStats::selectionCount(const QString& muscleId) const
{
    return counts_.value(muscleId, 0);
}

QString MuscleStats::mostPopularMuscle() const
{
    QString bestId;
    int bestCount = 0;

    for (auto it = counts_.begin(); it != counts_.end(); ++it)
    {
        if (it.value() > bestCount)
        {
            bestCount = it.value();
            bestId = it.key();
        }
    }

    return bestId;
}

QStringList MuscleStats::recentSelections() const
{
    return recent_;
}

int MuscleStats::totalSelections() const
{
    return totalSelections_;
}
