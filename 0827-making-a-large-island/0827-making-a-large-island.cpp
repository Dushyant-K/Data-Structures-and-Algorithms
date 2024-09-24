class disjointSet{
    private:
    vector<int> parent;
    public:
    vector<int> size;
    disjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
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
        if(parent1==parent2)return;

        if(size[parent1]<size[parent2]){
            parent[parent1]=parent2;
            size[parent2]+=size[parent1];
        }
        else if(size[parent1]>size[parent2]){
            parent[parent2]=parent1;
            size[parent1]+=size[parent2];
        }
        else{
            parent[parent2]=parent1;
            size[parent1]+=size[parent2];
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n){
        return (row>=0&&row<n&&col>=0&&col<n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        disjointSet ds(n*n-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int newRow = i+drow[k];
                        int newCol = j+dcol[k];
                        int node = i*n+j;
                        int adjNode = newRow*n+newCol;
                        if(isValid(newRow,newCol,n)&&grid[newRow][newCol]==1){
                            ds.unionSet(node,adjNode);
                        }
                    }
                }
            }
        }

        //Now we have the setup ready  
        int largestIsland=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int count=0;
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int adjRow = i+drow[k];
                        int adjCol = j+dcol[k];
                        if(isValid(adjRow,adjCol,n)&&grid[adjRow][adjCol]==1){
                            int node = i*n+j;
                            int adjNode = adjRow*n+adjCol;
                            if(st.find(ds.findUParent(adjNode))==st.end()){
                                count+=ds.size[ds.findUParent(adjNode)];
                                st.insert(ds.findUParent(adjNode));
                            }
                        }
                    }
                    largestIsland = max(largestIsland,count+1);
                }
            }
        }  
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            largestIsland = max(largestIsland, ds.size[ds.findUParent(cellNo)]);
        }  
        return largestIsland;
    }
};