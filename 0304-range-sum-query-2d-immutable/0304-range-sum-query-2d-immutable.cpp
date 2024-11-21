class NumMatrix {
    private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        prefixSum.resize(n,vector<int>(m));
        //Initializing the prefix Matrix
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=matrix[i][j];
                prefixSum[i][j]=sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //Now calculating sum of rectangle in O(1)
        int sum=0;
        for(int i=row1;i<=row2;i++){
            if(col1!=0)sum+=prefixSum[i][col2]-prefixSum[i][col1-1];
            else sum+=prefixSum[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */