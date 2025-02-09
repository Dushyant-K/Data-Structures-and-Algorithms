class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //Approach-1
        int n=nums.size();

        long long ans=0;
        int i=0;
        while(i<n){
            int j=0;
            while(j<i){
                if(nums[j]-nums[i]!=j-i)ans++;
                j++;
            }
            i++;
        }
        return ans;
    }
};