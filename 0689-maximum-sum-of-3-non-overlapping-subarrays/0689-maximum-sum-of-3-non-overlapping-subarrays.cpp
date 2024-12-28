class Solution {
    public:
    vector<vector<int>> dp = vector<vector<int>>(20001, vector<int>(4, -1));
    void solve(vector<int>& subarray, int idx, int count, int k, vector<int>& result){
        if(count==0)return;
        if(idx>=subarray.size())return;

        int take=subarray[idx]+helper(subarray,idx+k,count-1,k);
        int not_take=helper(subarray,idx+1,count,k);

        if(take>=not_take){
            result.push_back(idx);
            solve(subarray,idx+k,count-1,k,result);
        }
        else{
            solve(subarray,idx+1,count,k,result);
        }
    }

    int helper(vector<int>& subarray, int idx, int count, int k){
        if(count==0)return 0;
        if(idx>=subarray.size())return INT_MIN;

        if(dp[idx][count]!=-1)return dp[idx][count];

        int take=subarray[idx]+helper(subarray,idx+k,count-1,k);
        int not_take=helper(subarray,idx+1,count,k);

        return dp[idx][count]=max(take,not_take);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //Approach-1
        int n=nums.size();
        vector<int> subarrays;
        int i=0;
        int j=0;
        int windowSum=0;
        while(j<n){
            windowSum+=nums[j];
            if(j-i+1==k){
                subarrays.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;
        solve(subarrays,0,3,k,result);
        return result;
    }
};