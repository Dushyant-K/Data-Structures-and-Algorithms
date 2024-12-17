class Solution {
    private:
        // Directions for 4-connected grid movement: up, down, left, right
    const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // DFS to mark the first island cells as '2'
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q) {
        int n = grid.size();
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) return;
        
        grid[x][y] = 2; // Mark this cell as part of the first island
        q.push({x, y}); // Add to the BFS queue
        
        for (auto [dx, dy] : directions) {
            dfs(grid, x + dx, y + dy, q);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        //Approach-1
        int n = grid.size();
        queue<pair<int, int>> q; // For BFS starting from the first island cells
        
        // Step 1: Find the first island and mark it as '2'
        bool found = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        // Step 2: BFS from the first island to find the shortest bridge to the second island
        int flips = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    // If out of bounds, skip
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                    // If we reach the second island
                    if (grid[nx][ny] == 1) return flips;

                    // If we find water (0), mark it as visited (2) and add to queue
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            ++flips; // Increment the number of flips after each level of BFS
        }
        
        return -1;
    }
};