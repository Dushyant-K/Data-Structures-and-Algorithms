class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Approach-1
        // vector<int> ans;
        // int n = nums.size();
        // int min = (int) (n/3)+1;
        // map<int,int> mpp;
        // for(int i=0;i<n;i++){
        //    mpp[nums[i]]++;
        //    if(mpp[nums[i]]==min){
        //     ans.push_back(nums[i]);
        //    }
        // }
        // return ans;

        //Approach-2
        int n=nums.size();
        int count1=0;
        int count2=0;
        int element1,element2;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(count1==0&&nums[i]!=element2){
                count1=1;
                element1=nums[i];
            }
            else if(count2==0&&nums[i]!=element1){
                count2=1;
                element2=nums[i];
            }
            else if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element1)
            cnt1++;
            else if(nums[i]==element2)
            cnt2++;
        }
        int mini = (int)(n/3)+1;
        if(cnt1>=mini)
        ans.push_back(element1);
        if(cnt2>=mini)
        ans.push_back(element2);

        return ans;
    }
};