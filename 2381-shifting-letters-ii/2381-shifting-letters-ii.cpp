class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //Approach-1
        int n=s.length();
        vector<int> shift(n+1,0);
        for(auto it:shifts){
            int l=it[0];
            int r=it[1];
            int direction=it[2];
            if(direction==1){
                shift[l]+=1;
                shift[r+1]+=-1;
            }
            else{
                shift[l]+=-1;
                shift[r+1]+=1;
            }
        }

        int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=shift[i];
            
            int newAscii = ((s[i] - 'a') + prefixSum % 26 + 26) % 26 + 'a';
            s[i] = newAscii;
        }

        return s;
    }
};