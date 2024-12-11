class Solution {
public:
    int minJumps(vector<int>& arr) {
    //Approach-1(BFS Algorithim)
    int n=arr.size();
    if(n==0)return 0;
    unordered_map<int,set<int>>adj;
    for(int i=0;i<n;i++){
        adj[arr[i]].insert(i);
    }
    queue<pair<int,int>>q;
        vector<int>vis(n,0);
        vis[0]=1;
        q.push({0,0});
        int ans=1e9;
        while(!q.empty()){
            auto data=q.front();
            int currtime=data.first;
            int currind=data.second;
           
            vis[currind]=1;
            q.pop();

            if(currind==n-1) {
              ans=min(ans,currtime);
            }
            if(currind+1<n && !vis[currind+1]){
                q.push({currtime+1,currind+1});
            }
             if(currind-1>=0 && !vis[currind-1]){
                q.push({currtime+1,currind-1});
            }
            for(auto &it:adj[arr[currind]]){
                if(!vis[it]){
                    q.push({currtime+1,it});
                }
            }
           adj[arr[currind]].clear();
        
        }
return ans;
    }
};