class Solution {
    private:
    int helper(int n){
        int count=0;

        while(n>0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }

        return count;
    }
public:
    vector<int> countBits(int n) {
        //Approach-1
        // vector<int> ans(n+1);

        // for(int i=0;i<=n;i++){
        //     ans[i] = helper(i);
        // }

        // return ans;

        //Approach-2(Optimal Approach)
        vector<int> ans(n+1,0);

        for(int i=1;i<=n;i++){
            if(i%2==0){
                ans[i]=ans[i/2];
            }else{
                ans[i]=ans[i/2]+1;
            }
        }

        return ans;
    }
};