//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // Approach-1
        int n=mat.size();
        int m=mat[0].size();
        
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        
        vector<int> ans;
        while(left<=right&&top<=bottom){
            int firstRow=left;
            while(firstRow<=right){
                ans.push_back(mat[top][firstRow]);
                firstRow++;
            }
            top++;
            
            int lastColumn=top;
            while(lastColumn<=bottom){
                ans.push_back(mat[lastColumn][right]);
                lastColumn++;
            }
            right--;
            
            int lastRow=right;
            if(top<=bottom){
                while(lastRow>=left){
                ans.push_back(mat[bottom][lastRow]);
                lastRow--;
            }
            bottom--;
            }
            
            if(left<=right){
                int firstCol=bottom;
            while(firstCol>=top){
                ans.push_back(mat[firstCol][left]);
                firstCol--;
            }
            left++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends