#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "user.hpp"
#include "simulation_params.hpp"
#include <vector>

class Scheduler {
public:
    Scheduler(const SimulationParams& params);
    void addUser(User user);
    void runSimulation();
    void writeResults();

private:
    SimulationParams params;
    std::vector<User> users;
    int current_tti;
    void scheduleRoundRobin();
    void scheduleProportionalFair();
    void calculateMetricsForTti();
};

#endif