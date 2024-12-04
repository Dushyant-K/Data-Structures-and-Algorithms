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
        // Approach-1(Dijkstra's algorithim using set)
        set<pair<int,int>> st;
        int v=adj.size();
        vector<int> dist(v,1e9);
        st.insert({0,src});
        dist[src]=0;
        
        //Now the containers are ready
        while(!st.empty()){
            auto it = *(st.begin());
            int distance = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto &neighbor : adj[node]) {
                int neighborNode = neighbor.first;
                int weight = neighbor.second;
                
                // Relaxation step
                if (distance + weight < dist[neighborNode]) {
                    // If the neighbor already exists in the set, remove it
                    if (dist[neighborNode] != 1e9) {
                        st.erase({dist[neighborNode], neighborNode});
                    }
                    // Update the distance
                    dist[neighborNode] = distance + weight;
                    st.insert({dist[neighborNode], neighborNode});
                }
            }
        }
        
        vector<int> ans(v);
        for(int i=0;i<v;i++){
            if(dist[i]==1e9){
                ans[i]=-1;
                continue;
            }
            ans[i]=dist[i];
        }
        return ans;
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

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends