class Solution {
public:
    bool isPalindrome(string str){
        int length = str.length();

        int start=0;
        int end = length-1;

        while(start<end){
            if(str[start]!=str[end])return false;
            start++;
            end--;
        }

        return true;
    }
    void solve(int idx, int n, vector<string> partitions, vector<vector<string>>& ans, string& s){
        if(idx==n){
            ans.push_back(partitions);
            return;
        }

        for(int i=idx;i<n;i++){
            string str = s.substr(idx,i-idx+1);
            if(isPalindrome(str)){
                partitions.push_back(str);
                solve(i+1,n,partitions,ans,s);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //Approach-1 (Using Recursion and  backtracking)
        int n = s.length();
        vector<string> partitions;
        vector<vector<string>> ans;

        solve(0,n,partitions,ans,s);
        return ans;
    }
};