class Solution {
public:
    int n;
    vector<int> result;
    int resultScore=INT_MAX;
    void solve(vector<int>& perm, vector<int>& visited, int score, vector<int>& nums){
        if(score>resultScore)return;
        if(perm.size()==n){
            score+=abs(perm[n-1]-nums[perm[0]]);
            if(score<resultScore){
                resultScore=score;
                result=perm;
            }
            return;
        }
        for(int i=1;i<n;i++){
            if(visited[i])continue;
            perm.push_back(i);
            visited[i]=true;
            int s=perm.size();
            solve(perm,visited,score+abs(perm[s-2]-nums[perm[s-1]]),nums);
            perm.pop_back();
            visited[i]=false;
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        //Approach-1(Recursion backtracking)
        n=nums.size();
        vector<int> visited(n,0);
        vector<int> perm={0};
        visited[0]=true;//Trick-If we get a perm of min cost then we can just cycle it because of the dependency the score will be the same and hence the one starting with 0 will be lexicographically smallest
        solve(perm,visited,0,nums);
        return result;
    }
};