//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    static bool comparator(pair<int,int> pair1, pair<int,int> pair2){
        double val1 = (double)pair1.first / pair1.second;
        double val2 = (double)pair2.first / pair2.second;
        return val1 > val2;
    }
    int solve(int idx, int weight, vector<int> wt, vector<int> val, vector<vector<int>>& dp){
        if(idx==0){
            if(wt[0]<=weight)return(val[0]*(weight/wt[0]));
            return 0;
        }
        if(dp[idx][weight]!=-1)return dp[idx][weight];
        //pick/notPIck Method
        int notTake = 0+solve(idx-1,weight,wt,val,dp);
        int take = INT_MIN;
        if(weight>=wt[idx]){
            take = val[idx]+solve(idx,weight-wt[idx],wt,val,dp);
        }
        return dp[idx][weight]=(max(take,notTake));
    }
  public:
    int knapSack(int w, vector<int>& val, vector<int>& wt) {
        // Approach-1
        // vector<pair<int,int>> ds;
        // int n =val.size();
        // for(int i=0;i<n;i++){
        //     ds.push_back(make_pair(val[i],wt[i]));
        // }
        // sort(ds.begin(),ds.end(), comparator);
        
        // int profit=0;
        // for(int i=0;i<n;i++){
        //     while(w>=ds[i].second){
        //         profit+=ds[i].first;
        //         w=w-ds[i].second;
        //     }
        // }
        // return profit;
        
        //Approach-2(Memoization Method-Top down dynamic programming)
        // int n = val.size();
        // vector<vector<int>> dp(n,vector<int>(w+1,-1));
        // return solve(n-1,w,wt,val,dp);
        
        //Approach-3(Tabulation Method-Bottom up dynamic programming)
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(w+1,0));
        for(int i=wt[0];i<=w;i++){
            dp[0][i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = 0+dp[i-1][j];
                int take = INT_MIN;
                if(j>=wt[i]){
                    take = val[i]+dp[i][j-wt[i]];
                }
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends