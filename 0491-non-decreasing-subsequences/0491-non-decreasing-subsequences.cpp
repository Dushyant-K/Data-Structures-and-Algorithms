class Solution {
    int n;
public:
   void solve(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
   if(ds.size() >= 2) {
        ans.push_back(ds);
    }
    if(idx >= n) return;

    unordered_set<int> st;  
    for(int i = idx; i < n; i++) {
        if ((ds.empty() || nums[i] >= ds.back()) && st.find(nums[i]) == st.end()) {
                ds.push_back(nums[i]);  // Choose the current element
                solve(i + 1, nums, ds, ans);  // Recurse for the next elements
                ds.pop_back();  // Backtrack
                st.insert(nums[i]);  // Mark the element as used at this level
            }
    }
   }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //Approach-1(Recursion)
        n=nums.size();
        if(n<=1)return {};
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,nums,ds,ans);
        return ans;
    }
};