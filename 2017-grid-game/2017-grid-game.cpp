class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        //Approach-1(Recursion-backracking(Leap of faith))
        int n=grid[0].size();
        
        long long firstRowRemainingSum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowRemainingSum=0;

        long long robot2MinimizedPoints=LONG_LONG_MAX;

        for(int col=0;col<n;col++){
            //Robot1-picking strategy
            firstRowRemainingSum-=grid[0][col];

            //Robot2 will pick the best strategy available to him
        long long robot2MaxPoints=max(firstRowRemainingSum,secondRowRemainingSum);

            robot2MinimizedPoints= min(robot2MinimizedPoints,robot2MaxPoints);

            secondRowRemainingSum+=grid[1][col];
        }

        return robot2MinimizedPoints;
    }
};