class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //Approach-1
        // int n=nums.size();
        // if(n<2)return 0;
        // sort(nums.begin(),nums.end());
        // int maxi=0;
        // for(int i=1;i<n;i++){
        //     maxi=max(maxi,nums[i]-nums[i-1]);
        // }
        // return maxi;

    //Approach-2(Optimal Approach)
     if (nums.size() < 2) return 0;

    // Find the minimum and maximum elements in the array
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    // Edge case: all elements are the same
    if (minVal == maxVal) return 0;

    int n = nums.size();
    int bucketSize = max(1, (maxVal - minVal) / (n - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    // Create buckets to store min and max values
    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    vector<bool> bucketUsed(bucketCount, false);

    // Place elements into buckets
    for (int num : nums) {
        int idx = (num - minVal) / bucketSize;
        bucketMin[idx] = min(bucketMin[idx], num);
        bucketMax[idx] = max(bucketMax[idx], num);
        bucketUsed[idx] = true;
    }

    // Calculate the maximum gap
    int maxGap = 0;
    int prevMax = minVal;
    for (int i = 0; i < bucketCount; ++i) {
        if (!bucketUsed[i]) continue;
        maxGap = max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return maxGap;
    }
};