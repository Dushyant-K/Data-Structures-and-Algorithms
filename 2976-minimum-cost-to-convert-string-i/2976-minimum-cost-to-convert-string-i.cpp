class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //Approach-1(Floyd-Warshall Algorithim)
        // int n1=source.size();
        // int n2=target.size();

        // int mod=1e9;

        // if(n1!=n2)return -1;
        // vector<vector<long long>> adj(26,vector<long long>(26,LLONG_MAX));
        // int n=original.size();
        // for(int i=0;i<n;i++){
        //     adj[original[i]-'a'][changed[i]-'a']=cost[i];
        // }

        // for (int i = 0; i < 26; i++) {
        //     adj[i][i] = 0;
        // }

        // for(int i=0;i<26;i++){
        //     for(int j=0;j<26;j++){
        //         for(int k=0;k<26;k++){
        //             adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
        //         }
        //     }
        // }

        // int i=0;
        // long long minCost=0;
        // while(i<n1){
        //     char charA=source[i];
        //     char charB=target[i];
        //     if(charA==charB){
        //         i++;
        //         continue;
        //     }
        //     if(adj[charA-'a'][charB-'a']==LLONG_MAX)return -1;
        //     minCost+=adj[charA-'a'][charB-'a'];
        //     i++;
        // }
        // return minCost;

        //Approach-2
        const int inf = 1 << 29;
        int g[26][26];
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
            }
        }
        return ans;
    }
};