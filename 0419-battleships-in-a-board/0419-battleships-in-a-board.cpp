class Solution {
    private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[row][col]=1;

        int n=board.size();
        int m=board[0].size();


        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nextRow=row+drow[i];
            int nextCol=col+dcol[i];
            if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&board[nextRow][nextCol]=='X'&&visited[nextRow][nextCol]==0){
                dfs(nextRow,nextCol,board,visited);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        //Approach-1(DFS Traversal)
        int n=board.size();
        int m=board[0].size();

        if(!n||!m)return 0;

        vector<vector<int>> visited(n,vector<int>(m,0));

        int battleships=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'&&visited[i][j]==0){
                    dfs(i,j,board,visited);
                    battleships++;
                }
            }
        }

        return battleships;
    }
};