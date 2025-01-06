class Solution {
public: 
    void solve(int digit, int number, int required, int k, int base, vector<int>& ans){
        if(required==0){
            ans.push_back(number);
            return;
        }
        int no1=digit+k;
        int no2=digit-k;

        if(no1>=0&&no1<=9){
            solve(no1,number+no1*pow(10,base),required-1,k,base-1,ans);
        }
        if(no2>=0&&no2<=9){
            solve(no2,number+no2*pow(10,base),required-1,k,base-1,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        //Approach-1(Recursion backtracking)
        int base=n-1;
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int number=i*pow(10,base);
            solve(i,number,n-1,k,base-1,ans);
        }
        return ans;
    }
};