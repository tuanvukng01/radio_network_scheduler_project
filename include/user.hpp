#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <random>

enum class TrafficType {
    VIDEO,
    BROWSING,
    LOW_LATENCY
};

class User {
public:
    User(int id, TrafficType type, int initial_data_rate);
    int getId() const;
    TrafficType getTrafficType() const;
    void allocateResources(int rb);
    void updateThroughput();
    double getThroughput() const;
    int getAllocatedRBs() const;
    void resetAllocation();

private:
    int user_id;
    TrafficType traffic_type;
    int allocated_rbs;
    double throughput;
    int initial_data_rate;
};

#endif