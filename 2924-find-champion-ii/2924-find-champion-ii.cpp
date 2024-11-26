class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        //Approach-1
        vector<int> adjList[n];
        for(auto it:edges){
            int first=it[0];
            int second=it[1];
            adjList[first].push_back(second);
        }
        vector<int> visited(n,0);
        int champion=-1;
        for(int i=0;i<n;i++){
            for(auto it:adjList[i]){
                visited[it]=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(++count==2)return -1;
                champion=i;
            }
        }
        return champion;
    }
};