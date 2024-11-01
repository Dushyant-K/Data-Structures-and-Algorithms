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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //Approach-1
        vector<vector<int>> ans;
        vector<int> ds;
        uniqueCombinations(0,candidates,target,ans,ds);
        return ans;
    }
};