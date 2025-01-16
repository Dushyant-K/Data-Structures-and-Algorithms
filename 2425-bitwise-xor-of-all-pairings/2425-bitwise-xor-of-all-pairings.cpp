class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //Approach-1(Bitmanipulation)
        int n1=nums1.size();
        int n2=nums2.size();

        int helperXor=0;
        for(int i=0;i<n1;i++){
            helperXor=helperXor^nums1[i];
        }
        if(n1%2==0){
            if(n2%2==0)return 0;
            else return helperXor;
        }

        int result=0;
        for(int i=0;i<n2;i++){
            result=result^helperXor^nums2[i];
        }

        return result;

    }
};