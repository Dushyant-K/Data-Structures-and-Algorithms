class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        vector<vector<int>> matrix(rows, vector<int>(cols));

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                matrix[r][c] = strs[r][c] - 'a';
            }
        }

        int count = 0;
        for(int c = 0; c < cols; c++){
            int maxi = matrix[0][c];
            for(int r = 1; r < rows; r++){
                if(matrix[r][c] < maxi){
                    count++;
                    break;
                }
                maxi = max(maxi, matrix[r][c]);
            }
        }
        return count;
    }
};
