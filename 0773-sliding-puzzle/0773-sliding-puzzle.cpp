class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
         // Target configuration
        string target = "123450";
        int rows = board.size();
        int cols = board[0].size();

        // Convert the board to a string for easier manipulation
        string start = "";
        int zeroPos = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                start += (board[i][j] + '0');
                if (board[i][j] == 0) zeroPos = i * cols + j;
            }
        }

        if (start == target) return 0;

        // Directions for adjacent cells
        vector<vector<int>> directions = {
            {1, 3},       // 0 can move to 1, 3
            {0, 2, 4},    // 1 can move to 0, 2, 4
            {1, 5},       // 2 can move to 1, 5
            {0, 4},       // 3 can move to 0, 4
            {1, 3, 5},    // 4 can move to 1, 3, 5
            {2, 4}        // 5 can move to 2, 4
        };

        // BFS
        queue<pair<string, int>> q; // {current state, position of 0}
        set<string> visited;
        q.push({start, zeroPos});
        visited.insert(start);
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [current, zeroPos] = q.front();
                q.pop();

                if (current == target) return moves;

                // Explore neighbors
                for (int neighbor : directions[zeroPos]) {
                    string nextState = current;
                    swap(nextState[zeroPos], nextState[neighbor]);
                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push({nextState, neighbor});
                    }
                }
            }
            ++moves;
        }

        return -1; // Unsolvable
    }
};