class Solution {
    private:
    int solve(int i, int j, unordered_map<int,int>& mpp, vector<int>& arr){
        int target=arr[j]-arr[i];

        if(mpp.find(target)!=mpp.end()&&mpp[target]<i){
            int k=mpp[target];
            return 1+solve(k,i,mpp,arr);
        }

        return 2;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //Approach-1(Recursion)
        int n=arr.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[arr[i]]=i;//arr[i] -> index
        }

        int result=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int length=solve(i,j,mpp,arr);
                if(length>=3){
                    result=max(result,length);
                }
            }
        }

        return result;
    }
};