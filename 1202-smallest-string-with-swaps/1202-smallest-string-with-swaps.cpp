class disjointSet{
    vector<int> parent,rank;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int node){
        if(parent[node]==node)return node;

        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int node1, int node2){
        int ulp_u=findUParent(node1);
        int ulp_v=findUParent(node2);

        if(ulp_u==ulp_v)return;

        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        disjointSet ds(n);
        for(auto it:pairs){
            int u=it[0];
            int v=it[1];
            ds.unionByRank(u,v);
        }      

         // Group indices by their ultimate parent
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int parent = ds.findUParent(i);
            groups[parent].push_back(i);
        }

        // Sort characters within each group and rearrange the string
        for (auto& [parent, indices] : groups) {
            string temp;
            for (int idx : indices) {
                temp.push_back(s[idx]);
            }
            sort(temp.begin(), temp.end());  // Sort characters lexicographically
            sort(indices.begin(), indices.end()); // Sort indices to place characters correctly
            for (int i = 0; i < indices.size(); i++) {
                s[indices[i]] = temp[i];
            }
        }

        return s;
    }
};