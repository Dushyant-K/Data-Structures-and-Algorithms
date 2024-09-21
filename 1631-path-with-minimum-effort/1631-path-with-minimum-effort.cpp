class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //Approach-1
        int n =heights.size();
        int m = heights[0].size();
        vector<vector<int>> minEffort(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        minEffort[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=0;i<4;i++){
                int newRow=row+drow[i];
                int newCol = col+dcol[i];
                if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m&&
       max(effort,abs(heights[row][col]-heights[newRow][newCol]))<minEffort[newRow][newCol]){
        minEffort[newRow][newCol]=max(effort,abs(heights[row][col]-heights[newRow][newCol]));
        pq.push({minEffort[newRow][newCol],{newRow,newCol}});
       }
            }
        }
        return minEffort[n-1][m-1];
    }
};