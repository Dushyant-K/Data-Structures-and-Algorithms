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
        // for(int i=n-k;i<=n-1;i++){
        //     temp.push_back(nums[i]);
        // }

        // for(int i=0;i<n-k;i++){
        //     nums[i+k]=nums[i];
        // }

        // for(int i=0;i<k;i++){
        //     nums[i]=temp[i];
        // }
       reverse(nums,0,n-(k+1));
       reverse(nums,n-k,n-1);
       reverse(nums,0,n-1);
    }
};