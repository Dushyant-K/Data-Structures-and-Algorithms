class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        //Approach-1
        // vector<int> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]<pivot)ans.push_back(nums[i]);
        // }
        // for(int i=0;i<n;i++){
        // if(nums[i]==pivot)ans.push_back(nums[i]);
        // }

        // for(int i=0;i<n;i++){
        //     if(nums[i]>pivot)ans.push_back(nums[i]);
        // }
        // return ans;

        //Approach-2
        int n=nums.size();
        int lessIdx=0;
        int equalCount=0;
        int greaterIdx=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)lessIdx++;
            if(nums[i]==pivot)equalCount++;
        }
        int equalIdx=lessIdx;
        lessIdx=0;
        greaterIdx=equalIdx+equalCount;

        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
               result[lessIdx++]=nums[i];
            }
            else if(nums[i]==pivot){
               result[equalIdx++]=nums[i];
            }
            else{
                result[greaterIdx++]=nums[i];
            }
        }
        return result;
        
    }
};