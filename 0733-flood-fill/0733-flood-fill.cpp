class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Approach-1
        int n = image.size();     // Number of rows
        int m = image[0].size();  // Number of columns
        int oldColor = image[sr][sc];  // The original color at the starting point
        
        // If the old color is the same as the new color, no need to proceed
        if (oldColor == color) return image;
        
        // BFS queue to explore the connected pixels
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;  // Change the starting pixel's color to the new color
        
        // Directions for moving in the grid: right, down, left, up
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Traverse all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                
                // Check if the new position is within bounds and matches the old color
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == oldColor) {
                    image[newRow][newCol] = color;  // Update the color
                    q.push({newRow, newCol});          // Add the pixel to the queue for further exploration
                }
            }
        }
        
        return image;
    }
};