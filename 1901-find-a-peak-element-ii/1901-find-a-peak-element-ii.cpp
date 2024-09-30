class Solution {
public:
    int findRow(vector<vector<int>> mat, int n, int m, int mid){
        int row = 0;
        for(int i=1;i<n;i++){
            if(mat[i][mid]>mat[row][mid]){
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //Approach-1
        int n = mat.size();
        int m = mat[0].size();
        int low=0;
        int high= m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row = findRow(mat,n,m,mid);
            int left=-1;
            int right=-1;
            if(mid-1>=0)left=mat[row][mid-1];
            if(mid+1<=m-1)right=mat[row][mid+1];
            if(mat[row][mid]>left&&mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};