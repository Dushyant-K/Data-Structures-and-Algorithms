class Solution {
public:
    void uniqueCombinations(int idx, vector<int> candidates, int target, vector<int> ds, set<vector<int>>& st){
        if(idx==candidates.size()){
            if(target==0&&st.find(ds)==st.end()){
                st.insert(ds);
            }
            return;
        }

        //Picking up the element;
        ds.push_back(candidates[idx]);
        uniqueCombinations(idx+1,candidates,target-candidates[idx],ds,st);
        //Not picking up the element
        ds.pop_back();
        uniqueCombinations(idx+1,candidates,target,ds,st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //Approach-1
        sort(candidates.begin(),candidates.end());
        set<vector<int>> st;
        vector<int> ds;
        uniqueCombinations(0,candidates,target,ds,st);
        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};