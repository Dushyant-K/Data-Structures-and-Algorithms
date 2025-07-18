class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<pair<int, int>> moves = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        
        int startRow = knightPos[1] - 1;
        int startCol = knightPos[0] - 1;
        int destRow = targetPos[1] - 1;
        int destCol = targetPos[0] - 1;

        q.push({{startRow, startCol}, 0});
        visited[startRow][startCol] = 1;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int row = curr.first.first;
            int col = curr.first.second;
            int steps = curr.second;
            
            if (row == destRow && col == destCol) return steps;
            
            for (auto& move : moves) {
                int newRow = row + move.first;
                int newCol = col + move.second;
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, steps + 1});
                }
            }
        }
        
        return -1;
    }
};
