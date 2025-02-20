class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //Cantor's Diagonization
        int n=nums.size();
        string ans="";

        for(int i=0;i<n;i++){
            ans+=(nums[i][i]=='0')?'1':'0';
        }
        return ans;
    }
};