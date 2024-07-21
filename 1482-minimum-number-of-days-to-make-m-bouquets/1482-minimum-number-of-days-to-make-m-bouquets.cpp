class Solution {
public:

    int calcBouquets(vector<int> bloomDay, int mid, int k){
        int count=0;
        int m=0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                if(count>=k){
                    m = m + count/k;
                }
                count=0;
            }
        }
        if(count==n){
            return (n/k);
        }
        m = m+count/k;
        return m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        if(((double)m*(double)k)>n){
            return -1;
        }
        for(int i=0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        } 
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            int result = calcBouquets(bloomDay,mid,k);
            if(result>=m){
                maxi = mid-1;
            }
            else{
                mini= mid+1;
            }
        }
        return mini;
    }
};