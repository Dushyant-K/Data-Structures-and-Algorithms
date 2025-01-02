class Solution {
    private:
    void solve(int idx, int target, vector<int> candidates, vector<int> ds, vector<vector<int>> &ans){
        if(idx==-1){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //take/notTake method
        solve(idx-1,target,candidates,ds,ans);
        ds.push_back(candidates[idx]);
        if(candidates[idx]<=target){
        solve(idx,target-candidates[idx],candidates,ds,ans);
        ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //Approach-1(Memoization Method-Top down dynamic programming)
        int n = candidates.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        vector<int> ds;
        vector<vector<int>> ans;
        solve(n-1,target,candidates,ds,ans);
        return ans;
    }
};