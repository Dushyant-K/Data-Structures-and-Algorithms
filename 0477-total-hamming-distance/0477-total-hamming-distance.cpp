class Solution {
public:
    int helper(int num1, int num2){
        int x = num1^num2;
        int count=0;

        while(x>0){
            if(x&1)count++;
            x=x>>1;
        }

        return count;
    }
    int totalHammingDistance(vector<int>& nums) {
        //Approach-1(Using Xor) -> Brute Force Approach
        // int n=nums.size();
        // int count=0;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         count+=helper(nums[i],nums[j]);
        //     }
        // }

        // return count;

        //Approach-2(Optimal Approach)

        int n = nums.size();
        int ans=0;

        for(int i=0;i<=31;i++){
            int set_bit=0;
            int unset_bit=0;
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<i))set_bit++;
                else unset_bit++;
            }
            ans+=set_bit*unset_bit;
        }

        return ans;
    }
};