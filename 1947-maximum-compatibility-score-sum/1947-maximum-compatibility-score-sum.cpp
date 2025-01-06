class Solution {
public:
    void solve(int idx, int score, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool>& used, int& maxi, int n){
        if(idx==n){
            maxi=max(maxi,score);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i])continue;
            int questions=students[idx].size();
            int temp=0;
            for(int j=0;j<questions;j++){
                if(students[idx][j]==mentors[i][j])temp++;
            }
            used[i]=true;
            solve(idx+1,score+temp,students,mentors, used,maxi,n);
            used[i]=false;
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      //Approach-1(Recursion backtracking)
      int n=students.size();
      vector<bool> used(n,0);
      int maxi=0;
      solve(0,0,students,mentors,used,maxi,n);
      return maxi;
    }
};