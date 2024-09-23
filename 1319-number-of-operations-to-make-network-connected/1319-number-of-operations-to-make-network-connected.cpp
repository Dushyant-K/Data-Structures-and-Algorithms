class disjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    disjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=findParent(node);
    }
    void unionSet(int node1, int node2){
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);
        if(parent1==parent2)return;

        if(rank[parent1]<rank[parent2]){
            parent[parent1]=parent2;
        }
        else if(rank[parent1]>rank[parent2]){
            parent[parent2]=parent1;
        }
        else{
             parent[parent2]=parent1;
             rank[parent1]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int extraEdges=0;
        int components=0;
        for(auto it:connections){
            int node = it[0];
            int adjNode = it[1];
            if(ds.findParent(node)==ds.findParent(adjNode)){
                extraEdges++;
            }
            else{
                ds.unionSet(node,adjNode);
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i)components++;
        }
        if(extraEdges>=components)return components-1;
        return -1;
    }
};