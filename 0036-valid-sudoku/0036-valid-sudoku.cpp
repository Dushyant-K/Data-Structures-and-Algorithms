class Solution {
private:
// Function to check if placing `num` at `board[row][col]` is valid
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        // Check the row
        if (board[row][i] == num && i != col) return false;

        // Check the column
        if (board[i][col] == num && i != row) return false;

        // Check the 3x3 sub-grid
        int subGridRow = 3 * (row / 3) + i / 3;
        int subGridCol = 3 * (col / 3) + i % 3;
        if (board[subGridRow][subGridCol] == num &&
            (subGridRow != row || subGridCol != col)) {
            return false;
        }
    }
    return true;
}
public:
bool isValidUnit(const vector<char>& unit) {
    unordered_set<char> seen;
    for (char num : unit) {
        if (num != '.') {
            if (seen.count(num)) {
                return false;
            }
            seen.insert(num);
        }
    }
    return true;
}

    bool isValidSudoku(vector<vector<char>>& board) {
    //     for (int row = 0; row < 9; ++row) {
    //     if (!isValidUnit(board[row])) {
    //         return false;
    //     }
    // }

    // // Check columns
    // for (int col = 0; col < 9; ++col) {
    //     vector<char> column;
    //     for (int row = 0; row < 9; ++row) {
    //         column.push_back(board[row][col]);
    //     }
    //     if (!isValidUnit(column)) {
    //         return false;
    //     }
    // }

    //     for(int boxRow = 0; boxRow < 3; ++boxRow) {
    //     for (int boxCol = 0; boxCol < 3; ++boxCol) {
    //         vector<char> box;
    //         for (int row = boxRow * 3; row < boxRow * 3 + 3; ++row) {
    //             for (int col = boxCol * 3; col < boxCol * 3 + 3; ++col) {
    //                 box.push_back(board[row][col]);
    //             }
    //         }
    //         if (!isValidUnit(box)) {
    //             return false;
    //         }
    //     }
    // }

    // return true;

    //Approach-2
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!='.'){
                if(!isValid(board,i,j,board[i][j]))return false;
            }
        }
    }
    return true;
    }
};