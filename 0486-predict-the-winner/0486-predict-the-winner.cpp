class Solution {
    private:
    bool findWinner(bool turn, int low, int high, int score1, int score2, vector<int>& nums){
        if (low > high) return score1 >= score2;

        if (turn) {  // Player 1's turn (Maximize Player 1's score)
            return findWinner(!turn, low + 1, high, score1 + nums[low], score2, nums) ||
                   findWinner(!turn, low, high - 1, score1 + nums[high], score2, nums);
        } else {  // Player 2's turn (Maximize Player 2's score)
            return findWinner(!turn, low + 1, high, score1, score2 + nums[low], nums) &&
                   findWinner(!turn, low, high - 1, score1, score2 + nums[high], nums);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        //Approach-1(Recursion)
        int n=nums.size();
        if(n==1)return true;

        return findWinner(true,0,n-1,0,0,nums);
    }
};