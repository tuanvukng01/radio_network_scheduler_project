
import subprocess
import json
import os

if not os.path.exists("../build/radio_scheduler"):
    print("Executable not found. Run `cmake .. && make` in the build directory first.")
    exit(1)

subprocess.run(["../build/radio_scheduler"])

with open("results.json", "r") as f:
    results = json.load(f)

print("Average Throughput: ", results["average_throughput"])
print("Total Throughput: ", results["total_throughput"])
print("Average Latency: ", results["average_latency"])
print("Resource Utilization: ", results["resource_utilization"])