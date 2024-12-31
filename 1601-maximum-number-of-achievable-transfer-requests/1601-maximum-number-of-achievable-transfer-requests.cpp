class Solution {
public:
    int size;
    void solve(int idx, int count, vector<vector<int>>& requests, vector<int>& buildings, int& maxi){
        if(idx==size){
            for(int i=0;i<buildings.size();i++){
                if(buildings[i]!=0)return;
            }
            maxi=max(maxi,count);
            return;
        }
        int building1=requests[idx][0];
        int building2=requests[idx][1];

        buildings[building1]--;
        buildings[building2]++;
        solve(idx+1,count+1,requests,buildings,maxi);

        buildings[building1]++;
        buildings[building2]--;
        solve(idx+1,count,requests,buildings,maxi);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        //Approach-1(Indegree and outDegree)
        int count=0;
        vector<int> buildings(n,0);
        size=requests.size();
        solve(0,0,requests,buildings,count);
        return count;
    }
};