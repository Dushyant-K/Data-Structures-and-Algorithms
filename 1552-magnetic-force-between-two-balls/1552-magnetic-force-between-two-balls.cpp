class Solution {
public:

    bool canWePlace(vector<int>position, int mid, int m){
        int n = position.size();
        int count=1;
        int last = position[0];
        for(int i=1;i<n;i++){
            if(position[i]-last>=mid){
                count++;
                last=position[i];
            }
        }
        if(count>=m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low=1;
        int high = position[n-1]-position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canWePlace(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};