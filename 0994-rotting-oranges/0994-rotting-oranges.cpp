class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Approach-1
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                      q.push({{i,j},0});
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        int t=0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t,time);
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&visited[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                    visited[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2&&grid[i][j]==1)return -1;
            }
        }
        return t;
    }
};