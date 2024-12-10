#include <iostream>
#include "scheduler.hpp"
#include "user.hpp"
#include "simulation_params.hpp"

int main(int argc, char** argv) {
    SimulationParams params;

    Scheduler scheduler(params);

    for (int i = 0; i < params.num_users; ++i) {
        TrafficType t = TrafficType::BROWSING;
        if (i % 3 == 0) t = TrafficType::VIDEO;
        else if (i % 3 == 1) t = TrafficType::BROWSING;
        else t = TrafficType::LOW_LATENCY;

        User u(i, t, 10);
        scheduler.addUser(u);
    }

    scheduler.runSimulation();

    std::cout << "Simulation completed. Results written to " << params.output_file << "\n";
    return 0;
}