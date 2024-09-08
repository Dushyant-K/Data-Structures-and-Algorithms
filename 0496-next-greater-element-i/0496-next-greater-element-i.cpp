class Solution {
public:
    void reverse(vector<int> arr){
        int n = arr.size();
        for(int i=0;i<=(n/2);i++){
            int swap = arr[i];
            arr[i] = arr[n-i];
            arr[n-i] = swap;
        }
        return;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nge[nums2.size()];
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
           while(!(st.empty())&&(nums2[i]>=st.top())){
                    st.pop();
                }
                if(st.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=st.top();
            }
             st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};