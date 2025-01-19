class Solution {
    private:
    bool solve(int currentUnit, int lastJump, unordered_set<int>& st, int lastStone, vector<vector<int>>& dp){
        if(currentUnit==lastStone)return true;
        if(dp[currentUnit][lastJump]!=-1)return dp[currentUnit][lastJump];

        if(lastJump-1>0&&st.find(currentUnit+lastJump-1)!=st.end()){
            if(solve(currentUnit+lastJump-1,lastJump-1,st,lastStone,dp))return dp[currentUnit][lastJump]=true;
        }
        if(st.find(currentUnit+lastJump)!=st.end()){
            if(solve(currentUnit+lastJump,lastJump,st,lastStone,dp))return dp[currentUnit][lastJump]=true;
        }
        if(st.find(currentUnit+lastJump+1)!=st.end()){
            if(solve(currentUnit+lastJump+1,lastJump+1,st,lastStone,dp))return dp[currentUnit][lastJump]=true;
        }

        return dp[currentUnit][lastJump]=false;
    }
public:
    bool canCross(vector<int>& stones) {
    //Approach-1(Memoization Method=Top down dynamic programming)
    int n=stones.size();
    if(n==1)return true;
    if(stones[1]-stones[0]!=1)return false;
    unordered_set<int> st;
    for(int i=0;i<n;i++)st.insert(stones[i]);

    vector<vector<int>> dp(stones[n-1]+1,vector<int>(stones[n-1]-stones[0]+1,-1));
    return solve(stones[1],1,st,stones[n-1],dp); 
    }
};