//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Approach-1(Relax all the edges N-1 times Sequentially)
        
        //Prepare the containers
        vector<int> distance(V,1e8);
        distance[src]=0;
        for(int i=1;i<V;i++){
            for(auto it: edges){
                int from = it[0];
                int to = it[1];
                int weight = it[2];
                
                //Start Relaxation of the nodes
                if(distance[from]!=1e8&&distance[from]+weight<distance[to]){
                    distance[to]=distance[from]+weight;
                }
            }
        }
        
        //Checking for a negative cycle
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                return {-1};
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends