class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0; // Optimization: Result is very close to 1 when n is large

        // Use memoization: dp[a][b] stores probability when A has a ml, B has b ml
        unordered_map<int, unordered_map<int, double>> dp;

        // Recursive lambda function
        function<double(int, int)> solve = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;

            if (dp[a][b]) return dp[a][b];

            dp[a][b] = 0.25 * (
                solve(a - 100, b) +
                solve(a - 75, b - 25) +
                solve(a - 50, b - 50) +
                solve(a - 25, b - 75)
            );

            return dp[a][b];
        };

        return solve(n, n);
    }
};
