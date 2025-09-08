class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //Approach-1(Using Sorting and Two Pointer)
        // int n = nums1.size();
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());

        // int ans=0;

        // for(int i=0;i<n;i++){
        //     // if(i!=0&&nums1[i]==nums1[i-1])continue;
        //     for(int j=0;j<n;j++){
        //         // if(j!=0&&nums2[j]==nums2[j-1])continue;
        //         int low = 0;
        //         int high = n-1;
        //         while(low<n&&high>=0){
        //             long long sum = nums1[i];
        //             sum+=nums2[j];
        //             sum+=nums3[low];
        //             sum+=nums4[high];
        //             if(sum==0){
        //                 ans++;
        //                 low++;
        //                 high--;
        //                 // while(low<n&&nums3[low]==nums3[low-1])low++;
        //                 // while(high>=0&&nums4[high]==nums4[high+1])high++;
        //             }
        //             else if(sum>0)high--;
        //             else low++;
        //         }
        //     }
        // }
        // return ans;

        //Approach-2(Using Hash Map)
        unordered_map<int, int> mp;
        int n = nums1.size();

        // Store all possible sums of nums1[i] + nums2[j]
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        int ans = 0;
        // For each possible sum of nums3[k] + nums4[l],
        // check if its negation exists in the map
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                if (mp.find(target) != mp.end()) {
                    ans += mp[target];
                }
            }
        }
        return ans;
    }
};