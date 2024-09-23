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

    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }
    void unionSet(int node1, int node2){
        int parent1 = findUParent(node1);
        int parent2 = findUParent(node2);
        if(parent1==parent2){
            return;
        }
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        //0-(n-1)-Row Number
        //1-(n-1+col+1)
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }    

        disjointSet ds(maxRow+maxCol+1);
        map<int,int> stoneNodes;
        for(auto it:stones){
            int row = it[0];
            int col = it[1]+maxRow+1;
            ds.unionSet(row,col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUParent(it.first)==it.first)cnt++;
        }
        return n-cnt;
    }
};