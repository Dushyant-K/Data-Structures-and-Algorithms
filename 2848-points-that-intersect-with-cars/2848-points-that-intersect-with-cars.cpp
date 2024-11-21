class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        //Approach-1
   vector<pair<int, int>> events;

    // Step 1: Create events for each car interval
    for (const auto& car : nums) {
        int start = car[0];
        int end = car[1];
        events.emplace_back(start, 1);   // Increment coverage at start
        events.emplace_back(end + 1, -1); // Decrement coverage after end
    }

    // Step 2: Sort events by position (and by type for consistency)
    sort(events.begin(), events.end());

    // Step 3: Sweep line to count covered points
    int coverage = 0, prev = -1, result = 0;
    for (const auto& [pos, type] : events) {
        // If we had active coverage, count the points since the last event
        if (coverage > 0 && prev != -1) {
            result += pos - prev;
        }

        // Update the coverage and set the previous position
        coverage += type;
        prev = pos;
    }

    return result;
    }
};