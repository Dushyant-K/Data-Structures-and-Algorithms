class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Approach-1
       int n = grid.size();           // Number of rows
        int m = grid[0].size();        // Number of columns
        
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Initialize the visited array
        queue<pair<pair<int, int>, int>> q;  // BFS queue: {{row, col}, time}
        
        // Step 1: Push all rotten oranges into the queue and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;  // Mark rotten oranges as visited
                    q.push({{i, j}, 0});  // Add them to the queue with time 0
                }
            }
        }
        
        // Directions for moving in the grid: right, down, left, up
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        int t = 0;  // Maximum time to rot all oranges
        
        // Step 2: Perform BFS to rot nearby fresh oranges
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            t = max(t, time);  // Track the maximum time
            
            // Traverse all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                // Check if the new position is within bounds and is a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 2;  // Mark as rotten
                    q.push({{nrow, ncol}, time + 1});  // Push the new rotten orange with updated time
                }
            }
        }
        
        // Step 3: Check if any fresh orange is left unvisited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 2) {
                    return -1;  // If any fresh orange is left, return -1
                }
            }
        }
        
        return t;
    }
};