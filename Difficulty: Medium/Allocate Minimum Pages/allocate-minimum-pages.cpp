class Solution {
    private:
    bool findStudentsRequired(vector<int>& arr, int capacity, int k){
        int n = arr.size();
        int count=1;
        
        int sum=arr[0];
        for(int i=1;i<n;i++){
            if(sum+arr[i]>capacity){
                count++;
                sum=0;
            }
            if(count>k)return false;
            sum+=arr[i];
        }
        return true;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        //Approach-1(Binary Search)
        int n = arr.size();
        int low = 0;
        int high = 0;
        if(k>n)return -1;
        
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high){
            int mid = (low+high)/2;
            bool flag = findStudentsRequired(arr,mid,k);
            if(flag){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};