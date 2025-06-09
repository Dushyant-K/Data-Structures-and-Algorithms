class Solution {
    private:
    int merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        
        int p1 = low;
        int p2 = mid+1;
        int count = 0;
        
        while(p1<=mid&&p2<=high){
            if(arr[p1]<=arr[p2]){
                temp.push_back(arr[p1]);
                p1++;
            }else{
                count+=mid-p1+1;
                temp.push_back(arr[p2]);
                p2++;
            }
        }
        
        while(p1<=mid){
            temp.push_back(arr[p1]);
            p1++;
        }
        while(p2<=high){
            temp.push_back(arr[p2]);
            p2++;
        }
        
        for(int i = low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high){
        if(low>=high)return 0;
        
        int mid = (low+high)/2;
        return mergeSort(arr,low,mid)+mergeSort(arr,mid+1,high)+merge(arr,low,mid,high);
    }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Approach-1(Using Merge Sort)
        int n = arr.size();
        
        return mergeSort(arr,0,n-1);
        
    }
};