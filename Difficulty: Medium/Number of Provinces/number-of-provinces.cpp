//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfsTraversal(int node, vector<int>& visited, vector<int> adjList[]){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp]=1;
            for(auto it:adjList[temp]){
                if(visited[it]==0){
                    q.push(it);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // Approach-1
        int n = adj.size();
        vector<int> visited(n,0);
        vector<int> adjList[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    adjList[i].push_back(j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                bfsTraversal(i,visited,adjList);
                provinces++;
            }
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends