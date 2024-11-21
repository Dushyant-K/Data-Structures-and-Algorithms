class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        for(int i=n;i!=0;i=i/10){
            int digit=i%10;
            nums.push_back(digit);
        }
        int n1=nums.size();
        reverse(nums.begin(),nums.end());
        int idx=-1;
        for(int i=n1-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return -1;
        }
        for(int i=n1-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        int low=idx+1;
        int high=n1-1;
        while(low<high){
            int temp=nums[low];
            nums[low]=nums[high];
            nums[high]=temp;
        }
        int newNo=0;
        for(int i=0;i<n1;i++){
            newNo=newNo*10+nums[i];
        }
        return newNo;
    }
};