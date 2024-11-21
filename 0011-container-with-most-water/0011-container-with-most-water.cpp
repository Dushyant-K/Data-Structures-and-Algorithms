class Solution {
public:
    int maxArea(vector<int>& height) {
        //Approach-1(Two pointer approach)
        int n=height.size();
        int maxVolume=0;
        int low=0;
        int high=n-1;
        while(low<high){
            int volume=(high-low)*min(height[high],height[low]);
            maxVolume=max(maxVolume,volume);
            if(height[low]<=height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxVolume;
    }
};