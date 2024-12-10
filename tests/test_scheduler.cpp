#include <gtest/gtest.h>
#include "scheduler.hpp"
#include "simulation_params.hpp"
#include "user.hpp"

TEST(SchedulerTest, BasicFunctionality) {
    SimulationParams params;
    params.num_users = 5;
    params.total_bandwidth = 50;
    params.simulation_time = 10;
    params.scheduling_algorithm = "round_robin";

    Scheduler scheduler(params);

    for (int i = 0; i < 5; ++i) {
        User u(i, TrafficType::BROWSING, 10);
        scheduler.addUser(u);
    }

    ASSERT_NO_THROW(scheduler.runSimulation());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}