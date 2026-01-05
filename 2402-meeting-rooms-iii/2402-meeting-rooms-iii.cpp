class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //Approach-1(Using Sorting plus heap)
        int noOfMeetings = meetings.size();
        if(noOfMeetings<=n)return 0;

        sort(meetings.begin(),meetings.end(),[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });

        vector<int> rooms(n,1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i;
        for(i=0;i<n;i++){
            pq.push({meetings[i][1],i});
        }

        int maxi = 1;
        int ans=0;
        while(i<noOfMeetings){
            auto it = pq.top();
            pq.pop();

            int duration = meetings[i][1]-meetings[i][0];
            pq.push({it.first+duration,it.second});
            rooms[it.second]++;
            if(maxi<rooms[it.second]){
                ans = it.second;
            }else if(maxi==rooms[it.second]){
                ans = min(ans,it.second);
            }

            maxi = max(maxi,rooms[it.second]);
            i++;
        }

        return ans;
    }
};