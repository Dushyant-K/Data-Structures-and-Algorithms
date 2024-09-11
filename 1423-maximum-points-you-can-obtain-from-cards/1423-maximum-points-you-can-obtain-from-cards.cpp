class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoints=0;
        int leftSum=0;
        int rightSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxPoints =leftSum;
        int idx=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[idx];
            idx--;
            maxPoints = max(maxPoints,leftSum+rightSum);
        }
        return maxPoints;
    }
};