class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        //Approach-1(Using Line Sweep Algorigthim)
        int n =nums.size();

        vector<pair<int,int>> points;
        for(auto it:nums){
            int start = it[0];
            int end = it[1];

            points.push_back({start,1});
            points.push_back({end+1,-1});
        }
        sort(points.begin(),points.end());

        int count = 0;
        int prev =-1;
        int coverage = 0;
        for(auto it:points)
        {
            int point = it.first;
            int val = it.second;
            if(coverage>0&&prev!=-1){
                count+=point-prev;
            }

            coverage+=val;
            prev=point;
        }

        return count;
    }
};