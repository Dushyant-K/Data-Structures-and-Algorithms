class Solution {
    private:
    int solve(int i, int j, unordered_map<int,int>& mpp, vector<int>& arr, vector<vector<int>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];

        int target=arr[j]-arr[i];

        if(mpp.find(target)!=mpp.end()&&mpp[target]<i){
            int k=mpp[target];
            return dp[i][j]=1+solve(k,i,mpp,arr,dp);
        }

        return dp[i][j]=2;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //Approach-1(Recursion)
        // int n=arr.size();
        // unordered_map<int,int> mpp;

        // for(int i=0;i<n;i++){
        //     mpp[arr[i]]=i;//arr[i] -> index
        // }

        // int result=0;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int length=solve(i,j,mpp,arr);
        //         if(length>=3){
        //             result=max(result,length);
        //         }
        //     }
        // }

        // return result;

        //Approach-2(Memoizaion Method- Top Down dynaic progeamming)
        int n=arr.size();
        unordered_map<int,int> mpp;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            mpp[arr[i]]=i;//arr[i] -> index
        }

        int result=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int length=solve(i,j,mpp,arr,dp);
                if(length>=3){
                    result=max(result,length);
                }
            }
        }

        return result;
    }
};