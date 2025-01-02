class Solution {
    private:
    void solve(int idx, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(idx==n){
            ans.push_back(ds);
            return;
        }

        //picking up the element
        ds.push_back(nums[idx]);
        solve(idx+1,ds,ans,nums,n);
        ds.pop_back();
        solve(idx+1,ds,ans,nums,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //Approach-1(Bit Manipulation Method)
        // int n = nums.size();
        // vector<vector<int>> ans;
        // for(int i=0;i<(1<<n);i++){
        //     vector<int> temp;
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j))
        //         temp.push_back(nums[j]);
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;

        //Approach-2(Recursion backtracking)
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ds,ans,nums,n);
        return ans;
    }
};