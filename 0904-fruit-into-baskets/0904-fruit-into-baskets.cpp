class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Approach-1(Sliding Window and two pointer)
        int n = fruits.size();
        unordered_map<int, int> mpp;

        int left = 0;
        int right = 0;
        int maxi = 0;

        while (right < n) {
            mpp[fruits[right]]++;

            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};