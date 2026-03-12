#pragma once

#include <QString>
#include <QStringList>
#include <vector>
#include <memory>
#include "WorkoutStep.h"

class WorkoutPlan
{
public:
    explicit WorkoutPlan(const QString& title = "")
        : title_(title) {}

    WorkoutPlan(const WorkoutPlan&) = delete;
    WorkoutPlan& operator=(const WorkoutPlan&) = delete;

    WorkoutPlan(WorkoutPlan&&) noexcept = default;
    WorkoutPlan& operator=(WorkoutPlan&&) noexcept = default;

    void addStep(std::unique_ptr<WorkoutStep> step)
    {
        steps_.push_back(std::move(step));
    }

    QString title() const
    {
        return title_;
    }

    QStringList toDisplayList() const
    {
        QStringList result;
        for (const auto& step : steps_)
        {
            result.append(step->displayText());
        }
        return result;
    }

    bool empty() const
    {
        return steps_.empty();
    }

private:
    QString title_;
    std::vector<std::unique_ptr<WorkoutStep>> steps_;
};
