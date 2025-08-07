class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n=fruits.size();
        int diag=0;
        for (int i=0; i<n; i++) diag+=fruits[i][i];

        // fill fruits[i][j] with 0 for i+j=n-2, i+j=n-3 
        for(int i=0; i<n-2; i++){
            fruits[i][n-2-i]=fruits[i][n-3-i]=0;
        }
        fruits[n-2][0]=0;

        // triangle east
        for (int i=1; i<n-1; i++) {
            int j0=max(i+1, n-i-1);
            for (int j=j0; j<n; j++) {
                fruits[i][j]+=max(
                    fruits[i-1][j-1],
                    max(fruits[i-1][j],
                    (j+1<n)?fruits[i-1][j+1]:0)
                );
            }
        }

        // triangle south
        for (int j=1; j<n-1; j++) {
            int i0=max(j+1, n-j-1);
            for (int i=i0; i<n; i++) {
                fruits[i][j]+=max(
                    fruits[i-1][j-1],
                    max(fruits[i][j-1],
                    (i+1<n)?fruits[i+1][j-1]:0)
                );
            }
        }

        return diag+fruits[n-2][n-1]+fruits[n-1][n-2];
    }
};