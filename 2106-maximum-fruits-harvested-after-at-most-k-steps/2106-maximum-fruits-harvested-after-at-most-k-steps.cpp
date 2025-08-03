class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int total = 0, result = 0;

        while (right < n) {
            total += fruits[right][1];

            // Shrink the window from the left if it's not reachable within k steps
            while (left <= right && !canReach(fruits[left][0], fruits[right][0], startPos, k)) {
                total -= fruits[left][1];
                left++;
            }

            result = max(result, total);
            right++;
        }

        return result;
    }

    // Determines if you can collect all fruits from leftPos to rightPos starting at startPos within k steps
    bool canReach(int leftPos, int rightPos, int startPos, int k) {
        // Either go start → left → right or start → right → left
        int option1 = abs(startPos - leftPos) + (rightPos - leftPos);
        int option2 = abs(startPos - rightPos) + (rightPos - leftPos);
        return min(option1, option2) <= k;
    }
};
