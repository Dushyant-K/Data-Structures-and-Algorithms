class Solution {
public:
    int solve(int idx, vector<int>& squares, int n){
        if(n == 0) return 0;
        if(idx < 0) return INT_MAX;

        int take = INT_MAX;
        if(squares[idx] <= n){
            take = solve(idx, squares, n - squares[idx]);
            if(take != INT_MAX) take += 1;
        }

        int not_take = solve(idx - 1, squares, n);

        return min(take, not_take);
    }

    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i * i <= n; i++){
            squares.push_back(i * i);
        }

        return solve(squares.size() - 1, squares, n);
    }
};
