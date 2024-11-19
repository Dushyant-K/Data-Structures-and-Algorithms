class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        //Approach-1(Brute force)
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j)continue;
        //         if(abs(i-j)<=indexDiff&&abs(nums[i]-nums[j])<=valueDiff)return true;
        //     }
        // }
        // return false;

        //Approach-2
        // int n=nums.size();
        // if(indexDiff==0||n==1)return false;//Edge-Case
        // int idx=0;
        // int high=0;
        // int low=0;
        // while(idx<n){
        //     low--;
        //     high++;
        //     while(high<n&&(high-idx<=indexDiff)){
        //         if(abs(nums[high]-nums[idx])<=valueDiff)return true;
        //         high++;
        //     }

        //     while(low>=0&&(idx-low<=indexDiff)){
        //         if(abs(nums[idx]-nums[low])<=valueDiff)return true;
        //         low--;
        //     }

        //     idx++;
        //     low=idx;
        //     high=idx;
        // }
        // return false;

        //Approach-3(Sliding Window Approach)
            if (nums.empty() || indexDiff <= 0 || valueDiff < 0) {
        return false;
    }

    // Use a set to maintain the sliding window
    set<long long> window;

    for (int i = 0; i < nums.size(); ++i) {
        // Ensure the set contains at most indexDiff elements
        if (i > indexDiff) {
            window.erase((long long)nums[i - indexDiff - 1]);
        }

        // Find the smallest number >= nums[i] - valueDiff
        auto lower = window.lower_bound((long long)nums[i] - valueDiff);

        // Check if the condition abs(nums[i] - nums[j]) <= valueDiff is met
        if (lower != window.end() && abs(*lower - nums[i]) <= valueDiff) {
            return true;
        }

        // Add current number to the set
        window.insert(nums[i]);
    }

    return false;
    }
};