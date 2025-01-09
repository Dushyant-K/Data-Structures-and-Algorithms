class Solution {
public:
    long long solve(int idx, vector<int> damages, vector<int>& dp){
        if(idx<=0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        //Take
        int take=damages[idx]+solve(idx-3,damages,dp);

        //Not Take
        int not_take=solve(idx-1,damages,dp);

        return dp[idx]=max(take,not_take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // int n=power.size();
        // int maxi=*max_element(power.begin(),power.end());

        // vector<int> damages(maxi+1,0);
        // for(int i=0;i<n;i++){
        //     damages[power[i]]+=power[i];
        // }

        // vector<int> dp(maxi+1,-1);
        // return solve(maxi,damages,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        // int n=power.size();
        // int maxi=*max_element(power.begin(),power.end());

        // vector<int> damages(maxi+1,0);
        // for(int i=0;i<n;i++){
        //     damages[power[i]]+=power[i];
        // }

        // vector<int> dp(maxi+1,0);
        
        // for(int i=1;i<=maxi;i++){
        //     int take=damages[i];
        //     if(i>2)take+=dp[i-3];

        //     int not_take=dp[i-1];

        //     dp[i]=max(take,not_take);
        // }
        // return dp[maxi];

    //Approach-3(Space optimization Method)
    // int n = power.size();
    // if (n == 0) return 0;

    // // Find the maximum element in the array
    // int maxi = *max_element(power.begin(), power.end());

    // // Use a hash map to store the accumulated damages instead of a large array
    // unordered_map<int, int> damages;
    // for (int num : power) {
    //     damages[num] += num;
    // }

    // // Variables to store previous states
    // long long prev1 = 0; // Represents dp[i-1]
    // long long prev2 = 0; // Represents dp[i-2]
    // long long prev3 = 0; // Represents dp[i-3]

    // // Iterate from 1 to maxi
    // for (int i = 1; i <= maxi; i++) {
    //     long long take = damages[i]; // Damage at current number
    //     if (i > 2) take += prev3; // Add dp[i-3] if applicable

    //     long long not_take = prev1; // Skip the current number

    //     long long curr = max(take, not_take); // Choose the best option

    //     // Update previous states
    //     prev3 = prev2;
    //     prev2 = prev1;
    //     prev1 = curr;
    // }

    // return prev1; // Maximum points

    //Approach-4
    if (power.empty()) return 0;

    // Step 1: Sort the input array
    sort(power.begin(), power.end());

    // Step 2: Compress input and calculate total points for each unique value
    vector<pair<int, int>> points; // Pair of (value, total points for value)
    int n = power.size();
    int i = 0;

    while (i < n) {
        int current = power[i];
        int sum = 0;

        while (i < n && power[i] == current) {
            sum += current;
            i++;
        }

        points.push_back({current, sum});
    }

    // Step 3: Space-optimized dynamic programming
    long long prev1 = 0; // dp[i-1]
    long long prev2 = 0; // dp[i-2]

    for (int j = 0; j < points.size(); j++) {
        long long take = points[j].second; // Total points for current value
        if (j > 0 && points[j].first == points[j - 1].first + 1) {
            take += prev2; // Add dp[i-2] if consecutive
        } else {
            take += prev1; // Add dp[i-1] if not consecutive
        }

        long long not_take = prev1; // Skip current value

        long long curr = max(take, not_take); // Maximize points
        prev2 = prev1; // Update dp[i-2]
        prev1 = curr;  // Update dp[i-1]
    }

    return prev1; // Maximum points
    }
};