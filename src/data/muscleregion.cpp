#include "muscleregionmodel.h"

MuscleRegionModel::MuscleRegionModel(QObject* parent)
    : QAbstractListModel(parent)
{
    resetToDefault();
}

int MuscleRegionModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) return 0;
    return regions_.size();
}

QVariant MuscleRegionModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) return {};
    int i = index.row();
    if (i < 0 || i >= regions_.size()) return {};

    const auto& r = regions_[i];
    switch (role) {
    case IdRole: return r.id;
    case NxRole: return r.nx;
    case NyRole: return r.ny;
    case NwRole: return r.nw;
    case NhRole: return r.nh;
    default: return {};
    }
}

QHash<int, QByteArray> MuscleRegionModel::roleNames() const
{
    return {
            { IdRole, "id" },
            { NxRole, "nx" },
            { NyRole, "ny" },
            { NwRole, "nw" },
            { NhRole, "nh" },
            };
}

void MuscleRegionModel::resetToDefault()
{
    beginResetModel();
    regions_.clear();

    // Координаты 0..1 (примерные, потом подвинете)
    regions_.push_back({ "chest",  0.150, 0.166, 0.169, 0.146 });
    regions_.push_back({ "abs",    0.195, 0.322, 0.091, 0.234 });
    regions_.push_back({ "biceps", 0.098, 0.259, 0.059, 0.137 });
    regions_.push_back({ "biceps", 0.326, 0.259, 0.059, 0.137 });
    regions_.push_back({ "quads",  0.186, 0.601, 0.072, 0.244 });
    regions_.push_back({ "quads",  0.264, 0.601, 0.072, 0.244 });
    regions_.push_back({ "calves", 0.195, 0.854, 0.059, 0.127 });
    regions_.push_back({ "calves", 0.267, 0.854, 0.059, 0.127 });
    regions_.push_back({ "lats",   0.671, 0.244, 0.098, 0.234 });
    regions_.push_back({ "lats",   0.781, 0.244, 0.098, 0.234 });

    endResetModel();
}
