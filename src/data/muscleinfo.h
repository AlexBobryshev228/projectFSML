#pragma once

#include <QString>
#include <QStringList>

class MuscleInfo
{
public:
    MuscleInfo() = default;

    MuscleInfo(const QString& id,
               const QString& name,
               const QString& description,
               const QStringList& exercises)
        : m_id(id),
        m_name(name),
        m_description(description),
        m_exercises(exercises)
    {
    }

    QString id() const { return m_id; }
    QString name() const { return m_name; }
    QString description() const { return m_description; }
    QStringList exercises() const { return m_exercises; }

private:
    QString m_id;
    QString m_name;
    QString m_description;
    QStringList m_exercises;
};
