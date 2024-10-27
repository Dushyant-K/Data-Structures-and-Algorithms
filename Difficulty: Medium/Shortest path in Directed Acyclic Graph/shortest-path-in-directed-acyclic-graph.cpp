//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int node, vector<int>& visited, vector<pair<int,int>> adj[], stack<int>& st){
        visited[node]=1;
        
        for(auto it: adj[node]){
            int neighbour = it.first;
            int weight = it.second;
            if(visited[neighbour]==0){
                topoSort(neighbour,visited,adj,st);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        //Approach-1
        vector<pair<int,int>> adj[V];
        for(int i=0;i<E;i++){
            int first = edges[i][0];
            int second = edges[i][1];
            int weight = edges[i][2];
            adj[first].push_back({second,weight});
        }
        
        //Perform a topological Sort
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(i,visited,adj,st);
            }
        }
        
        
        //At the top of the stack we have to ensure that we are starting form the node
        while(st.top()!=0){
            st.pop();
        }
        //Pop elements from the stack and start relaxation of the node
        vector<int> distance(V,1e9);
        distance[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it:adj[node]){
                int neighbour = it.first;
                int weight = it.second;
                if(distance[node]+weight<distance[neighbour]){
                    distance[neighbour]=distance[node]+weight;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(distance[i]==1e9)distance[i]=-1;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends