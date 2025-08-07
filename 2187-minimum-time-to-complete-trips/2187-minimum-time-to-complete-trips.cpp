class Solution {
public:
    bool checkPossible(long long times, vector<int>& time, int totalTrips) {
        long long trips = 0; // Change this from int to long long

        for(auto it : time){
            trips += times / it;
            // Optional: Early exit to prevent unnecessary computation
            if (trips >= totalTrips) return true;
        }

        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        // Use binary search to find minimum time
        long long low = 1;
        long long high = (long long)(*min_element(time.begin(), time.end())) * totalTrips;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (checkPossible(mid, time, totalTrips)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
