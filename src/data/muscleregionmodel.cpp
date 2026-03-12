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

    regions_.push_back({ "chest",  0.247, 0.2, 0.135, 0.09 });
    regions_.push_back({ "abs",    0.278, 0.285, 0.07, 0.18 });
    regions_.push_back({ "biceps", 0.22, 0.259, 0.03, 0.1 });
    regions_.push_back({ "biceps", 0.38, 0.259, 0.03, 0.1 });
    regions_.push_back({ "quads",  0.25, 0.5, 0.05, 0.2 });
    regions_.push_back({ "quads",  0.328, 0.5, 0.05, 0.2 });
    regions_.push_back({ "calves", 0.257, 0.7, 0.029, 0.127 });
    regions_.push_back({ "calves", 0.343, 0.7, 0.029, 0.127 });
    regions_.push_back({ "lats",   0.615, 0.21, 0.064, 0.2 });
    regions_.push_back({ "lats",   0.6958, 0.21, 0.064, 0.2 });

    endResetModel();
}
