class Solution {
public:
    int mod=1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long int> ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
        }
        //we can ignore the collsions as the order of the positions is insignificant in this problem
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                ans[i]=(ans[i]-d);
            }
            else{
                ans[i]=(ans[i]+d);
            }
        }
        long long int a=0;
        long long int pref=0;
        //imagine finding distance of a4 with all elements before it
        //(a4-a1)+(a4-a2)+(a4-a3)---> (a4+a4+a4)-(a1+a2+3)---->i*a4-prefixsum
        //this formula can be used only if the positions are sorted
        sort(ans.begin(), ans.end());
        for(int i=0; i<n; i++){
            a+=i*ans[i]-pref;
            a%=mod;
            pref+=ans[i];
        }
        return a;
    }
};