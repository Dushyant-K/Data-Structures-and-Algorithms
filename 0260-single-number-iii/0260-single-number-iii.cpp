class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //Approach-1(Bucket Method)
        int n = nums.size();
        int xor1 = 0;

        for(int i=0;i<n;i++){
            xor1 = xor1^nums[i];
        }

        int pos=0;
        while((xor1&(1<<pos))==0){
            pos++;
        }

        int bucket1=0;
        int bucket2=0;

        for(int i=0;i<n;i++){
            if(nums[i]&(1<<pos))bucket1 = bucket1^nums[i];
            else bucket2 = bucket2^nums[i];
        }

        return {bucket1,bucket2};
    }
};