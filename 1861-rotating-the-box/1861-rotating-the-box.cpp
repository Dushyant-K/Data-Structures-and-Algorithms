class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        //Approach-1
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>> rotate(m,vector<char>(n,'.'));
        for(int i=n-1;i>=0;i--){
            int col=m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='*'){
                    rotate[j][n-1-i]='*';
                    col=j-1;
                }
                else if(box[i][j]=='#'){
                        rotate[col][n-1-i]='#';
                        col--;
                }
            }
        }
        return rotate;
    }
};