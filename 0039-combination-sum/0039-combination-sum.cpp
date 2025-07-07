class Solution {
public:
    void uniqueCombinations(int idx, vector<int> candidates, int target, vector<vector<int>>& ans, vector<int> ds){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //Picking this element
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            uniqueCombinations(idx,candidates,target-candidates[idx],ans,ds);
            ds.pop_back();
        }
        //Not picking this element
        uniqueCombinations(idx+1,candidates,target,ans,ds);
    }
    void uniqueCombinations1(int idx, vector<int>& candidates, vector<int> ds, vector<vector<int>>& ans, int target, int n){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<n;i++){
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                uniqueCombinations1(i,candidates,ds,ans,target-candidates[i],n);
                ds.pop_back();
            }
            else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //Approach-1
        // vector<vector<int>> ans;
        // vector<int> ds;
        // uniqueCombinations(0,candidates,target,ans,ds);
        // return ans;

        //Approach-2(Using Recursion after sorting)
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(),candidates.end());
        uniqueCombinations1(0,candidates,ds,ans,target,n);

        return ans;
    }
};