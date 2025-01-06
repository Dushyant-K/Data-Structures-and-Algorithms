class Solution {
public:
    void solve(int n, char prev, string temp, vector<string>& ans){
        //Base-Case
        if(n==0){
            ans.push_back(temp);
            return;
        }

        for(char ch='a';ch<='c';ch++){
            if(ch!=prev){
                solve(n-1,ch,temp+ch,ans);
            }
        }
    }
    string getHappyString(int n, int k) {
        //Approach-1(Recursion backtracking)
        vector<string> ans;
        solve(n,'z',"",ans);
        if(ans.size()<k)return {};
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};