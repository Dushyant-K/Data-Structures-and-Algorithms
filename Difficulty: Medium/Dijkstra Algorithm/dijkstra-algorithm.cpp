//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Approach-1
        // Initialize the distance vector with a large value
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        // Min-heap priority queue to get the node with the smallest distance
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, S});

        // Standard Dijkstra's Algorithm
        while (!pq.empty()) {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse through all adjacent nodes of the current node
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                // If a shorter path to adjNode is found
                if (nodeDist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = nodeDist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Replace unreachable nodes' distances with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends