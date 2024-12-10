#ifndef METRICS_HPP
#define METRICS_HPP

#include <vector>
#include "user.hpp"

struct Metrics {
    double average_throughput;
    double total_throughput;
    double average_latency;
    double resource_utilization;
};

class MetricsCalculator {
public:
    static Metrics computeMetrics(const std::vector<User>& users, int total_rb);
};

#endif