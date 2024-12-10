#include "user.hpp"

User::User(int id, TrafficType type, int init_rate)
    : user_id(id),
      traffic_type(type),
      allocated_rbs(0),
      throughput(0.0),
      initial_data_rate(init_rate) {}

int User::getId() const {
    return user_id;
}

TrafficType User::getTrafficType() const {
    return traffic_type;
}

void User::allocateResources(int rb) {
    allocated_rbs = rb;
}

void User::updateThroughput() {
    throughput = allocated_rbs * (initial_data_rate / 10.0);
}

double User::getThroughput() const {
    return throughput;
}

int User::getAllocatedRBs() const {
    return allocated_rbs;
}

void User::resetAllocation() {
    allocated_rbs = 0;
}