# Trip-planner-using-knapsack

A C++ trip planner that uses the 0/1 Knapsack algorithm to maximize total attraction rating within a user-defined budget.

## Project Structure

```text
trip-planner/
├── .devcontainer/
│   └── devcontainer.json
├── .vscode/
│   └── extensions.json
├── src/
│   ├── main.cpp
│   ├── TripPlanner.cpp
│   └── TripPlanner.h
├── data/
│   └── attractions.csv
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Requirements

- CMake (>= 3.10)
- A C++17 compiler

## Build and Run (Terminal)

From repository root:

```bash
mkdir build
cd build
cmake ..
make
./TripPlanner
```

## Build and Run (VS Code / Codespaces)

1. Open the repository folder in VS Code or Codespaces.
2. Accept the CMake configure prompt if shown.
3. Use the CMake status bar actions to build and run the target.

## Data Format

`data/attractions.csv` uses this format:

```text
Name,Cost,Rating
```
