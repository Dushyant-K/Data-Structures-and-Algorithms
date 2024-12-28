class Solution {
    private:
    bool solve(int n){
        if(n%3!=0) return n==1;

        return solve(n/3);
    }
public:
    bool isPowerOfThree(int n) {
        //Approach-1(Recursion)
        if(n<=0)return false;

        return solve(n);
    }
};