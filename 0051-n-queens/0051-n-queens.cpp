class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, n, board, solutions, leftRow, upperDiagonal, lowerDiagonal);
        return solutions;
    }

private:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& solutions,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[col + row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                lowerDiagonal[col + row] = 1;
                solve(col + 1, n, board, solutions, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                lowerDiagonal[col + row] = 0;
            }
        }
    }
};