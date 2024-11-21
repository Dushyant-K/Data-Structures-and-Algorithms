class MyCalendarTwo {
    private:
    vector<pair<int,int>> calendar;
public:
    MyCalendarTwo() {
        calendar.clear();
    }
    
    bool book(int startTime, int endTime) {
        // Store events (start and end markers)
        vector<pair<int, int>> events;

        // Add all existing intervals to the events list
        for (auto it : calendar) {
            events.push_back({it.first, 1});    // Start of an interval
            events.push_back({it.second, -1}); // End of an interval
        }

        // Add the new interval to the events list
        events.push_back({startTime, 1});
        events.push_back({endTime, -1});

        // Sort events by time. If times are equal, sort by type (start before end).
        sort(events.begin(), events.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        // Sweep through events and check for overlaps
        int count = 0; // Active overlapping intervals
        for (auto it : events) {
            count += it.second; // Add or subtract based on event type
            if (count > 2) {
                return false; // Triple booking detected
            }
        }

        // If no triple booking, save the new booking
        calendar.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */