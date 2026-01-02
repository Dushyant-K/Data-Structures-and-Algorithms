class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        //Approach-1(Using Brute Force Approach)
        int length = nums.size();
        int n = length/2;

        unordered_map<int,int> freq;

        for(int i=0;i<length;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==n)return nums[i];
        }

        return -1;
    }
};