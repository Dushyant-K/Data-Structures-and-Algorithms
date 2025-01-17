class Solution {
    private:
    bool solve(int n, int firstElement, vector<int>& derived){
        
        vector<int> original(n);
        original[0]=firstElement;

        for(int i=1;i<n;i++){
            original[i]=original[i-1]^derived[i-1];
        }

        return (original[n-1]^original[0]==derived[n-1]);
    }
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //Approach-1(Recursion-backTracking)
        int n=derived.size();
        if(n==1)return true;

        return solve(n,0,derived)||solve(n,1,derived);
    }
};