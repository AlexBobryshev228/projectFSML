#pragma once
#include <QString>

struct MuscleRegion {
    QString id;
    double nx = 0;
    double ny = 0;
    double nw = 0.1;
    double nh = 0.1;
};
