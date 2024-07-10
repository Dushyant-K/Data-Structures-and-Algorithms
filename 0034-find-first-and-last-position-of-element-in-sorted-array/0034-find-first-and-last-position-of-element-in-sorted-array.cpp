class Solution {
public:

int firstOccurence(vector<int> nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int lastOccurence(vector<int> nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans = mid;
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccurence(nums,target);
        if(first==-1){
            return {-1,-1};
        }
        int last = lastOccurence(nums,target);
        return {first,last};
    }
};