#include "scheduler.hpp"
#include "metrics.hpp"
#include <fstream>
#include <random>
#include <iomanip> // For formatting output

Scheduler::Scheduler(const SimulationParams& p)
    : params(p), current_tti(0) {}

void Scheduler::addUser(User user) {
    users.push_back(user);
}

void Scheduler::runSimulation() {
    for (current_tti = 0; current_tti < params.simulation_time; ++current_tti) {
        // Reset allocations
        for (auto &u : users) {
            u.resetAllocation();
        }

        // Perform scheduling
        if (params.scheduling_algorithm == "proportional_fair") {
            scheduleProportionalFair();
        } else {
            scheduleRoundRobin();
        }

        // Update throughput
        for (auto &u : users) {
            u.updateThroughput();
        }
    }

    writeResults();
}

void Scheduler::scheduleRoundRobin() {
    // Simple round-robin: each user gets equal share of resources
    int rb_per_user = params.total_bandwidth / (int)users.size();
    for (auto &u : users) {
        u.allocateResources(rb_per_user);
    }
}

void Scheduler::scheduleProportionalFair() {
    // A simplistic proportional fair: allocate based on previous throughput
    // Lower previous throughput => more RBs.
    // sum of 1/throughput for weighting:
    double sum_weights = 0.0;
    for (auto &u : users) {
        double w = 1.0 / (1.0 + u.getThroughput());
        sum_weights += w;
    }
    for (auto &u : users) {
        double w = 1.0 / (1.0 + u.getThroughput());
        int alloc = (int)((w / sum_weights) * params.total_bandwidth);
        u.allocateResources(alloc);
    }
}

void Scheduler::writeResults() {
    Metrics m = MetricsCalculator::computeMetrics(users, params.total_bandwidth);

    // Open output file
    std::ofstream ofs(params.output_file);

    // Write overall metrics
    ofs << "Average Throughput: " << m.average_throughput << "\n";
    ofs << "Total Throughput: " << m.total_throughput << "\n";
    ofs << "Average Latency: " << m.average_latency << "\n";
    ofs << "Resource Utilization: " << m.resource_utilization << "\n\n";

    // Write per-user stats
    ofs << "User Statistics:\n";
    ofs << std::setw(10) << "User ID" << std::setw(20) << "Throughput\n";
    ofs << std::string(30, '-') << "\n";

    for (auto &u : users) {
        ofs << std::setw(10) << u.getId()
            << std::setw(20) << u.getThroughput() << "\n";
    }

    ofs.close();
}