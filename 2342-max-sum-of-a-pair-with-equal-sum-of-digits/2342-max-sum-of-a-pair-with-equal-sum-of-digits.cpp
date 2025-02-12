class Solution {
    private:
    int findDigitSum(int n){
        if(n>=0&&n<=9)return n;

        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        //Approach-1(Hash-Map)
        unordered_map<int, int> hash;
        int maxi = -1; // Initialize to -1 in case no valid pair is found

        for (int i = 0; i < nums.size(); i++) {
            int digitSum = findDigitSum(nums[i]);

            if (hash.find(digitSum) != hash.end()) {
                maxi = max(maxi, nums[i] + hash[digitSum]); // Use the actual value, not index
                hash[digitSum] = max(hash[digitSum], nums[i]); // Store the maximum value, not index
            } else {
                hash[digitSum] = nums[i]; // Store value, not index
            }
        }

        return maxi;
    }
};