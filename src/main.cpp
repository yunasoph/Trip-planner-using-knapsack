#include <iostream>
#include "TripPlanner.h"

// Define a macro fallback in case CMake doesn't pass the directory path
#ifndef DATA_DIR
#define DATA_DIR "./data/"
#endif

using namespace std;

int main() {
    TripPlanner planner;
    
    // Construct the file path using the CMake definition
    string filePath = string(DATA_DIR) + "attractions.csv";

    if (!planner.loadAttractions(filePath)) {
        cout << "Failed to load database. Exiting...\n";
        return 1;
    }

    int budget;
    cout << "🎒 Welcome to the Knapsack Trip Planner!\n";
    cout << "Enter your maximum budget: $";
    
    if (!(cin >> budget) || budget <= 0) {
        cout << "Invalid budget entered. Please restart and enter a positive number.\n";
        return 1;
    }

    cout << "\nCalculating your best itinerary...\n";
    planner.optimizeTrip(budget);

    return 0;
}
