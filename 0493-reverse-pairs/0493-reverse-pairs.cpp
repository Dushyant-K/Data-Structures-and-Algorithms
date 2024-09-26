class Solution {
public:
int count=0;
    void merge(vector<int>& nums,int low,int mid,int high){
        int left = low;
         int right = mid+1;
          vector<int> ans;
         while(left<=mid && right<=high){
             if(nums[left]<=nums[right]){
                 ans.push_back(nums[left]);
                 left++;
             }
             else if(nums[left]>nums[right]){
                 ans.push_back(nums[right]);
                 right++;
             }
         }
         
         while(left<=mid){
             ans.push_back(nums[left]);
             left++;
         }
         
         while(right<=high){
             ans.push_back(nums[right]);
             right++;
         }
         
         for(int i=low;i<=high;i++){
             nums[i]=ans[i-low];
         }
    } 

    int countPairs(vector<int>& nums,int low, int mid, int high){
        int count=0;
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>((long long)2*nums[right])){
                // count+=(mid-low+1);(Code added by me)
                right++;
            }
            count+=(right-(mid+1));
        }
        return count;
    }
    

    int mergeSort(vector<int>& nums,int low,int high){
        int count=0;
        if(low>=high)return count;
        int mid=(low+high)/2;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        //Approach-1(Brute Force)
        // long count=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>(2*(long)nums[j]))count++;
        //     }
        // }
        // return count;

        //Approach-2
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};