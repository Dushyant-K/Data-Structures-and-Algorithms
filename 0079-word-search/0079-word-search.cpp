class Solution {
public:
    bool check(int row, int col, int idx, vector<vector<char>> board, int n, int m, string word, vector<vector<int>>& visited){
        if(idx==word.size()){
            return true;
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nextRow = row+drow[i];
            int nextCol = col+dcol[i];
            if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&board[nextRow][nextCol]==word[idx]&&visited[nextRow][nextCol]==0){
                visited[nextRow][nextCol]=1;
                if(check(nextRow,nextCol,idx+1,board,n,m,word,visited))return true;
                visited[nextRow][nextCol]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //Approach-1
        int n = board.size();
        int m = board[0].size();
        int row=-1;
        int col=-1;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    if (check(i, j, 1, board, n, m, word, visited)) {
                        return true;
                    }
                    visited[i][j] = 0;
               }
            }
        }
        if(row==-1||col==-1)return false;

        return check(row,col,1,board,n,m,word,visited);
    }
};