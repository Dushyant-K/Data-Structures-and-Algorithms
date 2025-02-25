class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //Approach-1(Prefix Sum)
        int n=arr.size();
        int mod=1e9+7;

        int evenCount=1;;
        int oddCount=0;
        int count=0;
        int prefixSum=0;

        for(int i=0;i<n;i++){
            prefixSum+=arr[i];

            if(prefixSum%2==0){
                evenCount++;
                count=(count+oddCount)%mod;
            }else{
                oddCount++;
                count=(count+evenCount)%mod;
            }
        }
        return count;
    }
};