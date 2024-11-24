class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    long long totalSum = 0;
    int minAbsValue = INT_MAX;
    int negativeCount = 0;

    // Traverse the matrix to calculate the total sum of absolute values
    // and count the number of negative elements.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            totalSum += abs(matrix[i][j]);
            minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            if (matrix[i][j] < 0) {
                ++negativeCount;
            }
        }
    }

    // If the number of negative values is odd, we must flip one smallest absolute value
    // to ensure the final sum is maximized.
    if (negativeCount % 2 != 0) {
        totalSum -= 2 * minAbsValue;
    }

    return totalSum;
    }
};