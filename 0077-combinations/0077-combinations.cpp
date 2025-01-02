class Solution {
    private:
    void solve(int no, int k, vector<int>& ds, vector<vector<int>>&  ans, int n){
        if(k==0){
            ans.push_back(ds);
            return;
        }
        if(no>n)return;
        ds.push_back(no);
        solve(no+1,k-1,ds,ans,n);
        ds.pop_back();
        solve(no+1,k,ds,ans,n);
    }
public:
    vector<vector<int>> combine(int n, int k) {
      //Approach-1(Recursion with backtracking)
      vector<int> ds;
      vector<vector<int>> ans;
      solve(1,k,ds,ans,n);
      return ans;  
    }
};