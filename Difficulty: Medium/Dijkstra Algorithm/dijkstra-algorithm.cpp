//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Approach-1(Using a set)
        int n = adj.size();
        
        vector<int> distance(n,1e9);
        set<pair<int,int>> st;
        distance[src]=0;
        st.insert({0,src});
        
        //Begin the iteration
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int dist = it.first;
            int node = it.second;
            
            for(auto i:adj[node]){
                int neighbour = i.first;
                int weight = i.second;
                if(distance[neighbour]>dist+weight){
                    
                    if(distance[neighbour]!=1e9){
                        st.erase({distance[neighbour],neighbour});
                    }
                    
                    distance[neighbour]=dist+weight;
                    st.insert({distance[neighbour],neighbour});
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends