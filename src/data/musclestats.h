#pragma once

#include <QString>
#include <QStringList>
#include <QMap>

class MuscleStats
{
public:
    void registerSelection(const QString& muscleId);
    int selectionCount(const QString& muscleId) const;
    QString mostPopularMuscle() const;
    QStringList recentSelections() const;
    int totalSelections() const;

private:
    QMap<QString, int> counts_;
    QStringList recent_;
    int totalSelections_ = 0;
};
