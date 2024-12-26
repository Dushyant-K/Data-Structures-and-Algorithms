class Solution {
    private:
    int solve(int idx, int currSum, int target, vector<int>& nums, int n, string pattern, set<string>& st){
        if(idx==n){
            if(currSum==target&&st.find(pattern)==st.end()){
                st.insert(pattern);
                return 1;
            }
            return 0;
        }

        int l=solve(idx+1,currSum+nums[idx],target,nums,n,pattern+'+'+to_string(nums[idx]),st);
        
        int r=solve(idx+1,currSum-nums[idx],target,nums,n,pattern+'-'+to_string(nums[idx]),st);

        return l+r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //Approach-1
        int n=nums.size();
        if(n==0)return 0;
        set<string> st;
        return solve(0,0,target,nums,n,"",st);
    }
};