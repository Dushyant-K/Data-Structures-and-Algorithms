class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //Approach-1(Using Interval technique)
        int n = intervals.size();
        map<vector<int>,int> mpp;

        for(int i=0;i<n;i++)
        mpp[intervals[i]]=i;

        vector<int> ans(n,-1);
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n-1;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(end-start+1==1)ans[mpp[intervals[i]]]=mpp[intervals[i]];
            else{
                int j=i+1;
                while(j<n&&intervals[j][0]<end)j++;
                if(j!=n)ans[mpp[intervals[i]]]=mpp[intervals[j]];
            }
        }

        return ans;
    }
};