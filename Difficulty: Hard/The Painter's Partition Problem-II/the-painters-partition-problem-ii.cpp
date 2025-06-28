// User function template for C++

class Solution {
    private:
    bool isPossible(vector<int>& arr, int hours, int painters){
        int n=arr.size();
        int count=1;
        int sum=arr[0];
        for(int i=1;i<n;i++){
            if(sum+arr[i]>hours){
                count++;
                sum=0;
            }
            if(count>painters)return false;
            sum+=arr[i];
        }
        
        return true;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        //Approach-1(Binary Search)
        int n = arr.size();
        int low=0;
        int high = 0;
        
        for(int i=0;i<n;i++){
            low = max(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(arr,mid,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return low;
    }
};