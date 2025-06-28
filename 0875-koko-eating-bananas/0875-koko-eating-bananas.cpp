class Solution {
public:
    int hourstaken(int mid,vector<int>&piles,int h){
        int n=piles.size();
        long long hours=0;
        int remaining=0;
        for(int i=0;i<n;i++){
            hours+=(piles[i]+mid-1)/mid;
            if(hours>h) return -1;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        int ans=maxi;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int hours=hourstaken(mid,piles,h);
            if(hours==1){
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};