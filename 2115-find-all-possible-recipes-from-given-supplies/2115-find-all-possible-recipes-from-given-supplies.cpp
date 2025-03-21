class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //Approach-1(Topology Sorting)
        unordered_map<string,bool> mpp;
        for(auto it:supplies){
            mpp[it]=true;
        }

        int n=recipes.size();
        unordered_set<string> adj[n];
        queue<string> q;
        for(int i=0;i<n;i++){
            bool flag=true;
            for(auto it:ingredients[i]){
                if(mpp.find(it)==mpp.end()){
                    flag=false;
                    adj[i].insert(it);
                }
            }
            if(flag)q.push(recipes[i]);
        }

        vector<string> result;
        while(!q.empty()){
            string recipe=q.front();
            q.pop();
            result.push_back(recipe);

            for(int i=0;i<n;i++){
                if(adj[i].empty())continue;
                else{
                    if(adj[i].find(recipe)!=adj[i].end())adj[i].erase(recipe);
                    if(adj[i].empty())q.push(recipes[i]);
                }
            }
        }

        return result;
    }
};