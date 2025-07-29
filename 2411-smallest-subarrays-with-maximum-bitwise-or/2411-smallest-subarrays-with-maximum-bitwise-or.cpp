class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        //Approach-1(Brute Force Approach)
        // int n = nums.size();
        // vector<int> answer(n,0);

        // for(int i=0;i<n;i++){
        //     int maxXor=0;
        //     int xor1=0;
        //     int length=0;
        //     for(int j=i;j<=n-1;j++){
        //         xor1=xor1|nums[j];
        //         if(xor1>maxXor){
        //             maxXor=xor1;
        //             length = (j-i+1);
        //         }
        //     }
        //     answer[i]=length;
        // }

        // return answer;

        //Approach-2(using prefixOr)
        int n = nums.size();
        vector<int> answer(n, 1); // Default min length is 1
        vector<int> lastSeen(32, -1); // Track last seen position for each bit

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    lastSeen[b] = i;
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    maxReach = max(maxReach, lastSeen[b]);
                }
            }

            answer[i] = maxReach - i + 1;
        }

        return answer;

    }
};