class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        //Approach-1(Djikstra's Alorithim)
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
          
            for (int k = 0; k < 4; ++k) {
                int ni = i + directions[k].first;
                int nj = j + directions[k].second;
                
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int newCost = dist[i][j] + (grid[i][j] == k + 1 ? 0 : 1);
                    if (newCost < dist[ni][nj]) {
                        dist[ni][nj] = newCost;
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        
        return dist[m - 1][n - 1];
    }
};