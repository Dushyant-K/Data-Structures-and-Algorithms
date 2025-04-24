class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        //Approach-1(Using Xor Approach)
        int n = encoded.size();
        vector<int> ans(n+1);
        ans[0]=first;

        for(int i=0;i<n;i++){
            int element = first^encoded[i];
            ans[i+1]=element;
            first=element;
        }

        return ans;
    }
};