class Solution {
public:
    void solve(int idx, string temp, vector<bool>& used, vector<string>& result, int n){
        if(idx==n){
            result.push_back(temp);
            return;
        }

        for(int i=1;i<=n;i++){
            if(used[i])continue;
            used[i]=true;
            solve(idx+1,temp+to_string(i),used,result,n);
            used[i]=false;
        }
    }
    string getPermutation(int n, int k) {
      //Approach-1(Recursion backtracking)
      vector<bool> used(n+1,0);
      vector<string> result;
      solve(0,"",used,result,n);
      return result[k-1];  
    }
};