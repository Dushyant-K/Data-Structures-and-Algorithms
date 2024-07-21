class Solution {
public:

    int isPossible(vector<int>weights, int capacity, int d){
        int reqDays=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>capacity){
                reqDays++;
                sum=0;
            }
            sum+=weights[i];
        }
        if(reqDays<=d){
            return 1;
        }
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // int n = weights.size();
        int mini=INT_MIN;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            mini = max(mini,weights[i]);
            sum+=weights[i];
        }
        int low=mini;
        int high = sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};