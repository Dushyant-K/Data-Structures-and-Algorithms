class Solution {
    vector<int> generateRows(int row){
        int ans=1;
        vector<int> temp;
        temp.push_back(ans);
        for(int j=1;j<row;j++){
            ans = ans*(row-j);
            ans = ans/j;
            temp.push_back(ans);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};