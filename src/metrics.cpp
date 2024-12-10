#include "metrics.hpp"
#include <numeric>

Metrics MetricsCalculator::computeMetrics(const std::vector<User>& users, int total_rb) {
    Metrics m;
    double sum_throughput = 0.0;
    for (auto &u : users) {
        sum_throughput += u.getThroughput();
    }
    m.total_throughput = sum_throughput;
    m.average_throughput = sum_throughput / users.size();
    m.average_latency = 100.0 / (1.0 + m.average_throughput);
    double used_rb = 0.0;
    for (auto &u : users) {
        used_rb += u.getAllocatedRBs();
    }
    m.resource_utilization = used_rb / total_rb;

    return m;
}