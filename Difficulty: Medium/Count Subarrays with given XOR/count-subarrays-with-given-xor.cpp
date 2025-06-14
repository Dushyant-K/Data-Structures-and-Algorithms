class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // Approach-1(Prefix xor approach )
        int n = arr.size();
        int count=0;
        int prefixXor=0;
        
        unordered_map<int,int> mpp;
        mpp[0]=1;
        
        int i=0;
        while(i<n){
            prefixXor^=arr[i];
            
            int rem = prefixXor^k;
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            
            mpp[prefixXor]++;
            i++;
        }
        
        return count;
        
    }
};