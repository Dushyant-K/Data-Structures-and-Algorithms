class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //Approach-1(Using Brute force Approach)
        int n = fruits.size();

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    count++;
                    break;
                }
            }
        }

        return n-count;

    }
};