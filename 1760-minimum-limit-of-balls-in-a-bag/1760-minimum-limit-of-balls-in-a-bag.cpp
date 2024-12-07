class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
    const int n=nums.size();
    // sort(nums.begin(), nums.end());
        int l=1, r=*max_element(nums.begin(), nums.end()), m;
        while(l<r){
            m=(l+r)/2;
            long long cnt=0;
            for(int j=0; j<n && cnt<=maxOperations; j++)
                cnt+=(nums[j]-1)/m;
            if(cnt<=maxOperations) r=m;
            else l=m+1;
        }
        return r;
    }
};