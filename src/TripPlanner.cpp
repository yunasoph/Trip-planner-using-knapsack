#include "TripPlanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

bool TripPlanner::loadAttractions(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    attractions.clear();
    string line, name, costStr, ratingStr;
    
    // Read line by line
    while (getline(file, line)) {
        stringstream ss(line);
        if (getline(ss, name, ',') && 
            getline(ss, costStr, ',') && 
            getline(ss, ratingStr, ',')) {
            try {
                Attraction attr;
                attr.name = name;
                attr.cost = stoi(costStr);
                attr.rating = stoi(ratingStr);

                if (attr.cost > 0 && attr.rating >= 0) {
                    attractions.push_back(attr);
                } else {
                    cerr << "Warning: Skipping invalid row: " << line << endl;
                }
            } catch (const exception&) {
                cerr << "Warning: Skipping malformed row: " << line << endl;
            }
        }
    }
    file.close();
    return true;
}

void TripPlanner::optimizeTrip(int maxBudget) {
    if (attractions.empty()) {
        cout << "No attractions loaded.\n";
        return;
    }

    int n = attractions.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxBudget + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxBudget; w++) {
            if (attractions[i - 1].cost <= w) {
                dp[i][w] = max(
                    attractions[i - 1].rating + dp[i - 1][w - attractions[i - 1].cost], 
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find selected items
    int currentEnjoyment = dp[n][maxBudget];
    int w = maxBudget;
    int totalSpent = 0;
    vector<Attraction> selected;

    for (int i = n; i > 0 && currentEnjoyment > 0; i--) {
        if (currentEnjoyment != dp[i - 1][w]) {
            selected.push_back(attractions[i - 1]);
            currentEnjoyment -= attractions[i - 1].rating;
            w -= attractions[i - 1].cost;
            totalSpent += attractions[i - 1].cost;
        }
    }

    // Output results
    cout << "\n====================================\n";
    cout << "         OPTIMAL TRIP PLAN          \n";
    cout << "====================================\n";
    cout << "Budget Allowed: $" << maxBudget << "\n";
    cout << "Money Spent: $" << totalSpent << "\n";
    cout << "Total Rating: " << dp[n][maxBudget] << " points\n\n";
    
    cout << "Itinerary:\n";
    for (const auto& item : selected) {
        cout << " -> " << item.name << " ($" << item.cost << ", " << item.rating << "/10)\n";
    }
    cout << "====================================\n";
}
