class Solution {
public:
    void solve(int idx, unordered_set<string>& st, int& maxi, string& s, int n){
        if(idx==n){
            int length=st.size();
            maxi=max(maxi,length);
            return;
        }

        for(int i=idx;i<n;i++){
            string str=s.substr(idx,i-idx+1);
            if(st.find(str)==st.end()){
                st.insert(str);
                solve(i+1,st,maxi,s,n);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        //Approach-1(Recursion backtracking)
        int n=s.length();
        unordered_set<string> st;
        int maxi=0;
        solve(0,st,maxi,s,n);
        return maxi;
    }
};