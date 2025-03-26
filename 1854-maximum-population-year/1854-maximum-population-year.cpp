class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //Approach-1(Range-Sum)
        int n=logs.size();
        vector<pair<int,int>> population;

        for(auto it:logs){
            int birth = it[0];
            int death = it[1];
            population.push_back({birth,1});
            population.push_back({death,-1});
        }

        sort(population.begin(),population.end());
        int count=0;
        int maxCount=0;
        int ans = INT_MAX;
        for(auto it:population){
            int year=it.first;
            int value=it.second;
            count+=value;
            if(count>maxCount){
                maxCount=count;
                ans=year;
            }
        }
        return ans;
    }
};