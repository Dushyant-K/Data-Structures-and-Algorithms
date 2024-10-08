//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    disjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node)return node;
        
        return parent[node]=findParent(parent[node]);
    }
    
    void unionSet(int node1, int node2){
        if(findParent(node1)==findParent(node2))return;
        
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);
        if(rank[parent1]<rank[parent2]){
            parent[parent1]=parent2;
        }
        else if(rank[parent2]<rank[parent1]){
            parent[parent2]=parent1;
        }
        else{
            parent[parent2]=parent1;
            rank[parent1]++;
        }
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prim's Algorithm
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        // vector<int> visited(V,0);
        // pq.push({0,0});
        // vector<pair<int,int>> mstEdges;
        // int sum=0;
        // while (!pq.empty()) {
        //     // Extract the edge with the smallest weight
        //     auto it = pq.top();
        //     pq.pop();

        //     int weight = it[0];
        //     int node = it[1];
        //     int parent = it[2];

        //     // If the node is already visited, skip it
        //     if (visited[node] == 1) continue;

        //     // Mark the node as visited and add the weight to the sum
        //     visited[node] = 1;
        //     sum += weight;

        //     // If it's not the starting node, add the edge to the MST
        //     if (parent != -1) {
        //         mstEdges.push_back({parent, node});
        //     }

        //     // Explore the adjacent nodes of the current node
        //     for (auto& neighbor : adj[node]) {
        //         int nextNode = neighbor[0];
        //         int nextWeight = neighbor[1];

        //         // If the adjacent node has not been visited, add it to the priority queue
        //         if (!visited[nextNode]) {
        //             pq.push({nextWeight, nextNode, node});
        //         }
        //     }
        // }
        
        // return sum;
        
        //Kruskal's Algorithm
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {i, adjNode}});
            }
        }
        
        disjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        
         for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) {
                mstWt += wt;
                ds.unionSet(u, v);
            }
        }
        return mstWt;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends