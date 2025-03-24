class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> finalMeetings;
        for (int i = 0; i < n; i++) {
            if (finalMeetings.empty() || finalMeetings.back()[1] < meetings[i][0]) {
                finalMeetings.push_back(meetings[i]);
            } else {
                finalMeetings.back()[1] = max(finalMeetings.back()[1], meetings[i][1]);
            }
        }

        if (finalMeetings.empty()) return days; // Edge case fix

        int count = finalMeetings[0][0] - 1;
        int m = finalMeetings.size();
        for (int i = 1; i < m; i++) {
            count += finalMeetings[i][0] - finalMeetings[i - 1][1] - 1;
        }

        count += days - finalMeetings.back()[1];

        return count;
    }
};
