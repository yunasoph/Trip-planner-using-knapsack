#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <string>
#include <vector>

struct Attraction {
    std::string name;
    int cost;
    int rating;
};

class TripPlanner {
private:
    std::vector<Attraction> attractions;

public:
    // Loads attractions from the CSV file
    bool loadAttractions(const std::string& filename);
    
    // Runs the 0/1 Knapsack algorithm
    void optimizeTrip(int maxBudget);
};

#endif
