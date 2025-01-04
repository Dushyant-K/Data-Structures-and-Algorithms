class Solution {
public:
    long long solve(int row, int col, vector<vector<int>>& grid, int n, int m){
        if(row<0||row>=n||col<0||col>=m||grid[row][col]==0)return 0;

        
        int originalGoldVal=grid[row][col];
        grid[row][col]=0;
        
        long long maxiGold=0;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int adjRow=row+drow[i];
            int adjCol=col+dcol[i];
            maxiGold=max(maxiGold,solve(adjRow,adjCol,grid,n,m));
        }

        grid[row][col]=originalGoldVal;

        return (long long)(originalGoldVal+maxiGold);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
       //Approach-1(Recursion backtracking)
       int n=grid.size();
       int m=grid[0].size();

       long long maxiGold=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                maxiGold=max(maxiGold,solve(i,j,grid,n,m));
            }
        }
       }
       return maxiGold;
    }
};