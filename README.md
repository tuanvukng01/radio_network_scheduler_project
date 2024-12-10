
# 📡 5G Radio Network Scheduler Simulation Tool

A lightweight simulation tool that mimics the functionality of a 5G radio network scheduler. This project demonstrates key aspects of software development for telecommunications, focusing on optimizing resource allocation in a simulated 5G environment.

---

## 🚀 Features

- **Basic Radio Scheduler:** Implements simple scheduling algorithms like Round-Robin and Proportional Fair Scheduling.
- **Priority Queue Management:** Manages resource allocation based on traffic type (e.g., video streaming, low-latency services).
- **Performance Metrics:** Displays key performance indicators such as throughput, latency, and resource utilization.
- **Visualization:** Generates intuitive graphs for analysis using Python.
- **Automation:** Automates testing and simulation runs with Python scripts.

---

## 🛠️ Tech Stack

- **Languages:** C++ (core scheduling logic), Python (data visualization and scripting)
- **Build Tools:** CMake
- **Version Control:** Git
- **Testing Framework:** Google Test
- **Visualization Tools:** Matplotlib

---

## 📂 Project Structure

```
radio_network_scheduler_project/
├── CMakeLists.txt          # Top-level build configuration
├── README.md               # Project documentation
├── build/                  # Build directory (created after running cmake)
├── include/                # Header files
│   ├── scheduler.hpp
│   ├── user.hpp
│   ├── simulation_params.hpp
│   └── metrics.hpp
├── src/                    # C++ source files
│   ├── scheduler.cpp
│   ├── user.cpp
│   ├── metrics.cpp
│   ├── main.cpp
│   └── simulation_params.cpp
├── tests/                  # Unit tests
│   ├── CMakeLists.txt
│   └── test_scheduler.cpp
└── python/                 # Python scripts
    ├── run_simulation.py
    ├── plot_results.py
    └── requirements.txt
```

---

## 🖥️ Getting Started

### Prerequisites

- Linux-based OS (e.g., Ubuntu)
- C++17 or higher
- Python 3.8 or higher
- CMake
- Matplotlib (Python)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/radio_network_scheduler_project.git
   cd radio_network_scheduler_project
   ```

2. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the scheduler:
   ```bash
   ./scheduler
   ```

4. Run the visualization script:
   ```bash
   python3 python/plot_results.py
   ```

[//]: # (---)

[//]: # ()
[//]: # (## 📊 Visualization Example)

[//]: # ()
[//]: # (![Visualization Example]&#40;https://via.placeholder.com/800x400.png&#41;)

---

## 📈 Metrics

- **Throughput:** Measures the data processed per unit of time.
- **Latency:** Tracks delays in resource allocation.
- **Utilization:** Examines how effectively resources are used.

---

## 🧪 Testing

Run unit tests with the following command:
```bash
cd build
ctest
```

---

## 📝 Future Enhancements

- Add support for dynamic scheduling algorithms.
- Integrate AI-based optimization for resource allocation.
- Expand visualization options for better data analysis.

---

## 🤝 Contributing

Contributions are welcome! Feel free to submit issues or pull requests. For major changes, please open an issue first to discuss your proposed changes.

---

## 📄 License

This project is licensed under the MIT License.

---

## 👨‍💻 Author

**Your Name**  
[GitHub](https://github.com/yourusername) | [LinkedIn](https://linkedin.com/in/yourusername)
