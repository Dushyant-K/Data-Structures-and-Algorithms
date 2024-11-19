class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //Approach-1(Sliding Window and two pointer question)
        int n=nums.size();
        if(k>n)return 0;
        long long maxi=0;
        int low=0;
        int high=0;
        long long sum=0;
        unordered_set<int> st;
        while(high<n){
           while(st.find(nums[high])!=st.end()){
            st.erase(nums[low]);
            sum-=nums[low];
            low++;
           }

           st.insert(nums[high]);
           sum+=nums[high];

           if(high-low+1==k){
            maxi=max(maxi,sum);

            st.erase(nums[low]);
            sum-=nums[low];
            low++;
           }
           high++;
        }
        return maxi;
    }
};