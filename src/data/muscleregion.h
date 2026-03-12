#pragma once
#include <QString>

// 1 зона клика поверх картинки
struct MuscleRegion {
    QString id;     // "biceps", "abs", "lats"...
    double nx = 0;  // 0..1 (проценты от ширины картинки)
    double ny = 0;  // 0..1
    double nw = 0.1;
    double nh = 0.1;
};
