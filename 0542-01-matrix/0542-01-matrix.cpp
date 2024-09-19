class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //Approach-1
        int n = mat.size();
        int m = mat[0].size();

        // Initialize visited array and distance array
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        // Enqueue all cells with value 0 and mark them visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        // Directions for moving up, down, left, and right
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        // Process the queue
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            // Update distance
            dist[row][col] = distance;

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                // Check if the new position is valid and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] == 0) {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, distance + 1});
                }
            }
        }

        return dist;
    }
};