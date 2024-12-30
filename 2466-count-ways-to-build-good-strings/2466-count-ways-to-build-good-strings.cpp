class Solution {
    private:
    int solve(string str, int low, int high, string zeros, string ones, unordered_map<string,int>& mpp){
        int n=str.length();
        if(n>high)return 0;
        if(mpp.find(str)!=mpp.end())return mpp[str];

        int left=solve(str+zeros,low,high,zeros,ones,mpp);
        int right=solve(str+ones,low,high,zeros,ones,mpp);

        if(n>=low&&n<=high)return mpp[str]=left+right+1;
        return mpp[str]=left+right;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        //Approach-1(Recursion)
        string zeros,ones;
        for(int i=0;i<zero;i++)zeros+='0';
        for(int i=0;i<one;i++)ones+='1';

        unordered_map<string,int> mpp;
        return solve("",low,high,zeros,ones,mpp);
    }
};