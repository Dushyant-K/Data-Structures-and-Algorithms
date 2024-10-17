class Solution {
public:
    static bool comparator(vector<int> interval1, vector<int> interval2){
        return interval1[1] < interval2[1];  // Sort by the end time of intervals
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        // Sort intervals based on their end time
        sort(intervals.begin(), intervals.end(), comparator);

        int count = 0;           // To count the number of intervals to be removed
        int lastEndTime = intervals[0][1];  // End time of the last non-overlapping interval

        // Start from the second interval and check for overlaps
        for (int i = 1; i < n; i++) {
            // If the current interval overlaps with the last non-overlapping interval
            if (intervals[i][0] < lastEndTime) {
                count++;  // Increment the removal count
            } else {
                // Update lastEndTime if there's no overlap
                lastEndTime = intervals[i][1];
            }
        }

        return count;
    }
};