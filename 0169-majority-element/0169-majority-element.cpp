class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int majorityElement=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majorityElement){
                count++;
            }
            else{
                count--;
                if(count<0){
                    majorityElement=nums[i];
                    count=1;
                }
            }
        }
        return majorityElement;
    }
};