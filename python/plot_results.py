
import json
import matplotlib.pyplot as plt

with open("results.json", "r") as f:
    data = json.load(f)

user_ids = [u["id"] for u in data["users"]]
throughputs = [u["throughput"] for u in data["users"]]

plt.bar(user_ids, throughputs)
plt.xlabel("User ID")
plt.ylabel("Throughput")
plt.title("Per-User Throughput")
plt.savefig("throughput_plot.png")
plt.show()