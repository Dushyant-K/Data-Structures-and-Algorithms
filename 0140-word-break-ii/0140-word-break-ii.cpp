class Solution {
public:
    void solve(int idx, string temp, unordered_set<string>& st, string s, vector<string>& ans, int n){
        if(idx==n){
            ans.push_back(temp);
        }

        for(int i=idx;i<n;i++){
            string str=s.substr(idx,i-idx+1);
            if(st.find(str)!=st.end()){
                string prev=temp;
                if(!temp.empty())temp+=" ";
                temp+=str;
                solve(i+1,temp,st,s,ans,n);
                temp=prev;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //Approach-1(Recursion backtracking)
        int n=s.length();
        vector<string> ans;
        unordered_set<string> st;
        for(auto it:wordDict){
            st.insert(it);
        }
        solve(0,"",st,s,ans,n);
        return ans;
    }
};