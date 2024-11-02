class Solution {
public:
    void uniqueCombinations(int start, int k ,int n, vector<int>ds, vector<vector<int>>& ans){
        if(k==0){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }

        //Second technique of generating all subsequences
        for(int i=start;i<=9;i++){
            if(i>n)break;
            ds.push_back(i);
            uniqueCombinations(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //Approach-1
        vector<int> ds;
        vector<vector<int>> ans;
        uniqueCombinations(1,k,n,ds,ans);
        return ans;
    }
};