class Solution {
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
        for (int row = 0; row < 9; ++row) {
        if (!isValidUnit(board[row])) {
            return false;
        }
    }

    // Check columns
    for (int col = 0; col < 9; ++col) {
        vector<char> column;
        for (int row = 0; row < 9; ++row) {
            column.push_back(board[row][col]);
        }
        if (!isValidUnit(column)) {
            return false;
        }
    }

        for(int boxRow = 0; boxRow < 3; ++boxRow) {
        for (int boxCol = 0; boxCol < 3; ++boxCol) {
            vector<char> box;
            for (int row = boxRow * 3; row < boxRow * 3 + 3; ++row) {
                for (int col = boxCol * 3; col < boxCol * 3 + 3; ++col) {
                    box.push_back(board[row][col]);
                }
            }
            if (!isValidUnit(box)) {
                return false;
            }
        }
    }

    return true;
    }
};