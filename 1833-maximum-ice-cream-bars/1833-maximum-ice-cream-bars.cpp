class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //Approach-1(Counting Sort)
        int n = costs.size();

        int maxi= *max_element(costs.begin(),costs.end());
        vector<int> count(maxi+1,0);

        for(int i=0;i<n;i++){
            count[costs[i]]++;
        }

        int bars = 0;

        for(int i=0;i<=maxi;i++){
            while(count[i]>0&&coins>=i){
                    coins = coins-i;
                    bars++;
                    count[i]--;
            }
            if(coins<i)break;
        }

        return bars;
    }
};