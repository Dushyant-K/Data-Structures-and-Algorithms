class Solution {
    private:
    int getMaxDistance(int mask, int n, vector<vector<int>> d /* copy */) {
    int res = 0;
    for (int k = 0; k < n; ++k) // Floyd-Warshall
        if (mask & (1 << k))
            for (int i = 0; i < n; ++i)
                if (i != k && mask & (1 << i))
                    for (int j = 0; j < n; ++j)
                        if (j != i && mask & (1 << j))
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
    for (int i = 0; i < n; ++i)
        if (mask & (1 << i))
            for (int j = i + 1; j < n; ++j)
                if (mask & (1 << j))
                    res = max(res, d[i][j]);
    return res;
}
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> d(n, vector<int>(n, 100000));
    for (auto &r : roads) {
        d[r[0]][r[1]] = min(d[r[0]][r[1]], r[2]);
        d[r[1]][r[0]] = min(d[r[1]][r[0]], r[2]);
    }
    int comb = 1 << n, res = 1;
    for (int mask = 1; mask < comb; ++mask)
        res += getMaxDistance(mask, n, d) <= maxDistance;
    return res; 
    }
};