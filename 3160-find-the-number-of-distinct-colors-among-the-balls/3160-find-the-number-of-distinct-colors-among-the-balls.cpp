class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        //Apporach-1(Hashmap)
        int n=queries.size();
        unordered_map<int,int> colors;
        unordered_map<int,int> freq;

        vector<int> ans;

        for(auto it:queries){
            int node=it[0];
            int color=it[1];

            if(colors.find(node)!=colors.end()){
                int nodeColor=colors[node];
                freq[nodeColor]--;
                if(freq[nodeColor]==0)freq.erase(nodeColor);
            }
            colors[node]=color;
            freq[color]++;

            ans.push_back(freq.size());
        }

        return ans;
    }
};