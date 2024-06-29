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

    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n=nums.size();
        k=k%n;
       reverse(nums,0,n-(k+1));
       reverse(nums,n-k,n-1);
       reverse(nums,0,n-1);
    }
};