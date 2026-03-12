#pragma once

#include <QAbstractListModel>
#include <QVector>
#include "muscleregion.h"

class MuscleRegionModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles { IdRole = Qt::UserRole + 1, NxRole, NyRole, NwRole, NhRole };
    Q_ENUM(Roles)

    explicit MuscleRegionModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void resetToDefault();

private:
    QVector<MuscleRegion> regions_;
};
