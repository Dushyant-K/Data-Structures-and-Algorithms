class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<bool>> isGuarded(m, vector<bool>(n, false));
    vector<vector<bool>> isObstacle(m, vector<bool>(n, false));
    
    // Mark the walls and guards as obstacles
    for (auto& guard : guards) {
        isObstacle[guard[0]][guard[1]] = true;
    }
    for (auto& wall : walls) {
        isObstacle[wall[0]][wall[1]] = true;
    }
    
    // Direction vectors for north, east, south, west
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    // Mark cells visible to guards
    for (auto& guard : guards) {
        int x = guard[0];
        int y = guard[1];
        
        for (auto& dir : directions) {
            int dx = dir.first, dy = dir.second;
            int nx = x + dx, ny = y + dy;
            while (nx >= 0 && ny >= 0 && nx < m && ny < n && !isObstacle[nx][ny]) {
                isGuarded[nx][ny] = true;
                nx += dx;
                ny += dy;
            }
        }
    }
    
    // Count unguarded cells
    int unguardedCount = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!isGuarded[i][j] && !isObstacle[i][j]) {
                ++unguardedCount;
            }
        }
    }
    
    return unguardedCount;
    }
};