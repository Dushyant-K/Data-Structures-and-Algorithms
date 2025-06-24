class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        //Approach-1
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        vector<int> maxCol(m,INT_MIN);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][i]=matrix[j][i];
                maxCol[i] = max(maxCol[i],matrix[j][i]);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[j][i]==-1){
                    ans[j][i]=maxCol[i];
                }
            }
        }

        return ans;
    }
};