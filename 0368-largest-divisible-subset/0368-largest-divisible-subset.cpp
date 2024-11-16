class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    //Approach-1(Memoization Method-top Down dynamic programming)
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    int maxi=1;
    int lastIndex=-1;
    
    for(int i=0; i<=n-1; i++){
        
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(nums[i]%nums[prev_index]==0&& 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    int idx=1;
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
    }
};