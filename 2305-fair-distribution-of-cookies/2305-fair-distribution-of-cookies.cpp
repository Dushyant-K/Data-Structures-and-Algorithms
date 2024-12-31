class Solution {
public:
    int n;
    void solve(int idx, int k, vector<int>& cookies, vector<int>& child, int currMaxi, int& mini){
        if(idx==n){
            mini=min(mini,currMaxi);
            return;
        }
        int temp=currMaxi;
        for(int i=1;i<=k;i++){
            child[i]+=cookies[idx];
            currMaxi=max(currMaxi,child[i]);
            solve(idx+1,k,cookies,child,currMaxi,mini);
            child[i]-=cookies[idx];
            currMaxi=temp;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        //Approach-1(Recursion)
        n=cookies.size();
        vector<int> child(k+1,0);
        int mini=INT_MAX;
        solve(0,k,cookies,child,INT_MIN,mini);
        return mini;
    }
};