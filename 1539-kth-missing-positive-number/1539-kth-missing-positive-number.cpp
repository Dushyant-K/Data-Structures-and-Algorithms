class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //1st Approach
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                k++;
            }
            else{
                return k;
            }
        }
        return k;
    }
};