class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row = 0, col = m - 1;
        int count = 0;

        while (row < n && col >= 0) {
            if (grid[row][col] < 0) {
                count += (n - row);
                col--;
            } else {
                row++;
            }
        }
        return count;
    }
};