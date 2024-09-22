class Solution {
public:
   void reverse(vector<int>& arr,int st,int end){
    while(st<end){
           int temp=arr[st];
           arr[st]=arr[end];
           arr[end]=temp;
           st++;
           end--;
       }
       }
    bool check(vector<int>& nums) {
        //Approach-1
        int idx=-1;
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)return true;
        reverse(nums,0,idx);
        reverse(nums,idx+1,n-1);
        reverse(nums,0,n-1);
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
};