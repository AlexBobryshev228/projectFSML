#include "DataStore.h"
#include <QStringList>

QStringList DataStore::allMuscleIds() const
{

    return {"biceps", "chest", "abs", "lats", "quads", "calves"};
}
QString DataStore::muscleName(const QString& id) const
{
    if (id == "biceps") return "Biceps";
    if (id == "chest")  return "Chest";
    if (id == "quads")  return "Quadriceps";
    if (id == "abs")  return "Abs";
    if (id == "lats") return "Lats";
    if (id == "calves") return "Calves";

    return "Неизвестно";
}

QString DataStore::muscleDescription(const QString& id) const
{
    if (id == "biceps") return "Front upper-arm muscles that flex the elbow and help rotate the forearm";
    if (id == "chest")  return "Muscles that push the arms forward and inward (pressing movements) and assist shoulder flexion";
    if (id == "quads")  return "Front thigh muscles that extend the knee and help stabilize the leg during standing and walking";
    if (id == "abs")  return "Core muscles that flex the trunk, stabilize the spine, and help maintain posture and balance.";
    if (id == "lats") return "Large back muscles that pull the arms down and back, helping with pull-ups, rows, and posture/stability.";
    if (id == "calves") return "Lower-leg muscles that point the foot downward (plantarflexion) and support walking, running, and jumping.";
    return "";
}
