class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
            // Sort events based on their end time
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = events.size();
    vector<int> maxValue(n, 0); // maxValue[i] stores the maximum value considering the first i events

    // Update maxValue array
    maxValue[0] = events[0][2];
    for (int i = 1; i < n; ++i) {
        maxValue[i] = max(maxValue[i - 1], events[i][2]);
    }

    int result = 0;
    
    // Iterate through events to calculate the maximum sum of values
    for (int i = 0; i < n; ++i) {
        // Option 1: Attend the current event
        result = max(result, events[i][2]);

        // Option 2: Find a non-overlapping event before the current event
        int low = 0, high = i - 1, lastValidIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][1] < events[i][0]) { // Check if the event is non-overlapping
                lastValidIndex = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Add the value of the last valid event to the current event's value
        if (lastValidIndex != -1) {
            result = max(result, events[i][2] + maxValue[lastValidIndex]);
        }
    }

    return result;
    }
};