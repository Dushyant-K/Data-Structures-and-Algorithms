class Solution {
public:
    long long flowerGame(int n, int m) {
        //Approach-1(Brute Force Approach)
        // long long ans=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if((i+j)%2!=0)ans++;
        //     }
        // } 

        // return ans;

        //Approach-2(Using Maths)
        return (long long)(n*m/2);
    }
};