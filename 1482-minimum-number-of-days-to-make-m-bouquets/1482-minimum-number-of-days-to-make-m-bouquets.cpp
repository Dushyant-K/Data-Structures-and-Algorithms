class Solution {
public:
    int calculateBouquets(vector<int> bloomDay, int mid, int k){
        int bouquets=0;
        int count=0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]>mid){
                count=0;
                continue;
            }
            count++;
            if(count==k){
                bouquets++;
                count=0;
            }
        }
        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Approach-1
        int n = bloomDay.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,bloomDay[i]);
        }
        int ans=-1;
        int low=1;
        int high = maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int noOfBouquets = calculateBouquets(bloomDay,mid,k);
            if(noOfBouquets>=m){
                ans=mid;
                high= mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};