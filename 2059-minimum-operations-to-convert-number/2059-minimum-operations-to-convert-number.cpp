class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        //Approach-1(BFS Algorithim)
        int n=nums.size();
        queue<pair<int,int>> q;
        vector<bool> visited(1001, false);
        visited[start]=true;
        q.push({0,start});

        while(!q.empty()){
            int distance=q.front().first;
            int node=q.front().second;
            q.pop();
            if(node==goal)return distance;
            if(node<0||node>1000)continue;
            for(int i=0;i<n;i++){
                int add=node+nums[i];
                int sub=node-nums[i];
                int xor1=node^nums[i];

                //Edge cases
                if(add==goal||sub==goal||xor1==goal)return distance+1;

                 if (add >= 0 && add <= 1000 && !visited[add]) {
                    visited[add] = true;
                    q.push({distance + 1, add});
                }
                if (sub >= 0 && sub <= 1000 && !visited[sub]) {
                    visited[sub] = true;
                    q.push({distance + 1, sub});
                }
                if (xor1 >= 0 && xor1 <= 1000 && !visited[xor1]) {
                    visited[xor1] = true;
                    q.push({distance + 1, xor1});
                }
            }
        }
        return -1;
    }
};