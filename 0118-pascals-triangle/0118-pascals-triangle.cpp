class Solution {
public:
vector<int>generateRows(int n){
    vector<int> result;
    result.push_back(1);
    int ans=1;
    for(int i=1;i<n;i++){
        ans = ans*(n-i);
        ans = ans/i;
        result.push_back(ans);
    }
    return result;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};