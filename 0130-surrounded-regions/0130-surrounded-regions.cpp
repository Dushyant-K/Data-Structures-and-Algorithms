class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> board, vector<vector<int>>& visited){
        visited[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int numsRow = row+drow[i];
            int numsCol = col+dcol[i];
            if(numsRow>=0&&numsRow<n&&numsCol>=0&&numsCol<m&&board[numsRow][numsCol]=='O'&&visited[numsRow][numsCol]==0){
                dfs(numsRow,numsCol,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O'&&visited[i][j]==0){
                    dfs(i,j,board,visited);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};