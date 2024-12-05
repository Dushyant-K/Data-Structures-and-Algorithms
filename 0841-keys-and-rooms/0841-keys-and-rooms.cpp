class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //Approach-1(BFS Algo)
        int n=rooms.size();
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0]=1;

        //Now the containers are ready
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0)return false;
        }
        return true;
    }
};