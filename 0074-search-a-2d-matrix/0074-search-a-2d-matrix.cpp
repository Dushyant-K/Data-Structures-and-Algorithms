class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n*m-1);
        while(low<=high){
            int mid = (low+high)/2;
            int row_no = mid/m;
            int col_no = mid%m;
            if(matrix[row_no][col_no]==target){
                return true;
            }

            else if(matrix[row_no][col_no]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};