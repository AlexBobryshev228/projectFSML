#pragma once

#include <QString>
#include <QStringList>
#include <QVector>

class MuscleSearchService
{
public:
    MuscleSearchService();
    QStringList search(const QString& query) const;

private:
    struct MuscleEntry {
        QString id;
        QString name;
    };

    QVector<MuscleEntry> muscles_;
};
