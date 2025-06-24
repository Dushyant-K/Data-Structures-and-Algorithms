class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        // Map to store diagonals using min-heap
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagMap;

        // Group elements by (i - j)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diagMap[i - j].push(mat[i][j]);
            }
        }

        // Sort and write back
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = diagMap[i - j].top();
                diagMap[i - j].pop();
            }
        }

        return mat;
    }
};
