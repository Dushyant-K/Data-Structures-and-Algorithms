class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //Approach-1(Binary Search+Validation)
        int n=arr.size();
        vector<int> prefixMax(n,INT_MIN);
        vector<int> suffixMin(n,INT_MAX);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[n-1-i]);
            prefixMax[i]=maxi;
            suffixMin[n-1-i]=mini;
        } 

        int chunksPossible=1;
        for(int i=1;i<n;i++){
            if(prefixMax[i-1]<suffixMin[i])chunksPossible++;
        }
        return chunksPossible;
    }
};