class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
       // containedBoxes here acts as the adj list
        
        int ans = 0;
        int n = candies.size();
        vector<int> vis(n, 0);      // for the boxes which we visited but are closed
        queue<int> q;
        
        for(int i = 0; i < initialBoxes.size(); i++){
            // if the box is open --> push in queue
            // if the box is closes (else condition) --> mark visited
            
            if(status[initialBoxes[i]]) q.push(initialBoxes[i]);
            else vis[initialBoxes[i]] = 1;
        }
        
        // BFS
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            ans += candies[top];
            for(auto it : containedBoxes[top]){
                // if the current box is open(i.e. status[it]) --> push in queue and mark the status as closed so that we don't open the box again 
                // else if the box is already closed --> mark it visited
                
                if(status[it]) {q.push(it); status[it] = 0;}
                else vis[it] = 1;
            }
            
            for(auto it : keys[top]){
                // If there are keys present in current box we open the boxes which are visited but locked 
                if(vis[it] && !status[it]) 
                    q.push(it);
                status[it] = 1;
            }
            
        }
        return ans;
    }
};