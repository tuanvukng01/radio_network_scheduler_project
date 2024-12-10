#ifndef SIMULATION_PARAMS_HPP
#define SIMULATION_PARAMS_HPP

#include <string>

struct SimulationParams {
    int num_users;
    int total_bandwidth;
    int simulation_time;
    std::string scheduling_algorithm;
    std::string output_file;


    SimulationParams()
        : num_users(10),
          total_bandwidth(100),
          simulation_time(1000),
          scheduling_algorithm("round_robin"),
          output_file("results.json") {}
};

#endif