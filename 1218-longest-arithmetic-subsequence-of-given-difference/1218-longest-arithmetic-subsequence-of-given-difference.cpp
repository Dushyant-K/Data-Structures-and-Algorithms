class Solution {
public:
    int solve(int idx, int difference, int prev, vector<int>& arr, map<pair<int,int>,int>& dp){
        if(idx<0){
            return 0;
        }
        if(dp.find({idx,prev})!=dp.end())return dp[{idx,prev}];
        int take=0;
        //Take
        if(prev==-1||(prev-arr[idx]==difference)){
            take=1+solve(idx-1,difference,arr[idx],arr,dp);
        }

        //Not_take
        int not_take=solve(idx-1,difference,prev,arr,dp);
        return dp[{idx,prev}]=max(take,not_take);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // int n=arr.size();
        // int maxi=*max_element(arr.begin(),arr.end());

        // map<pair<int,int>,int> dp;
        // return solve(n-1,difference,-1,arr,dp);

        unordered_map<int, int> dp; // Maps a number to the length of the longest subsequence ending with that number
        int maxLength = 0;

        for (int num : arr) {
            // If `num - difference` exists in the map, extend the subsequence, else start a new one.
            dp[num] = dp[num - difference] + 1;
            maxLength = max(maxLength, dp[num]);
        }

        return maxLength;
    }
};