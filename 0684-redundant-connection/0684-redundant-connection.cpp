 class disjointSet{
        vector<int> parent,rank;
        public:
        disjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUParent(int node){
            if(parent[node]==node)return node;

            return parent[node]=findUParent(parent[node]);
        }

        void unionByRank(int node1, int node2){
            int ulp_node1=findUParent(node1);
            int ulp_node2=findUParent(node2);

            if(ulp_node1==ulp_node2)return;

            if(rank[ulp_node1]>rank[ulp_node2]){
                parent[ulp_node2]=ulp_node1;
            }
            else if(rank[ulp_node2]>rank[ulp_node1]){
                parent[ulp_node1]=ulp_node2;
            }
            else{
                parent[ulp_node2]=ulp_node1;
                rank[ulp_node1]++;
            }
        }
    };
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //Approach-1(Disjoint Set)
        int n=edges.size();
        if(n<=1)return {};
        disjointSet ds(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            int ulp_u=ds.findUParent(u);
            int ulp_v=ds.findUParent(v);
            if(ulp_u==ulp_v)return {u,v};
            else ds.unionByRank(u,v);
        }

        return {};
    }
};