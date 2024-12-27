class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //Approach-1(Brute force)
        // int n=values.size();
        // int maxi=INT_MIN;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int score=values[i]+values[j]+(i-j);
        //         maxi=max(maxi,score);
        //     }
        // }
        // return maxi;

        //Approach-2(Special Observation-whenever an element is given with its index in a relation always try to rearrange the equation and try to get something out of it)
        int n=values.size();
        int maxi=values[0];
        int score=0;

        for(int i=1;i<n;i++){
            score=max(score,values[i]-i+maxi);
            maxi=max(maxi,values[i]+i);
        }
        return score;
    }
};