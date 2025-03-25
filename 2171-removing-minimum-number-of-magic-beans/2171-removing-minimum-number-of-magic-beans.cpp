class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        //Approach-1(PrefixSum Approach)
        int n=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long> prefixSum(n);

        prefixSum[0]=beans[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+beans[i];
        }

        long long ans= prefixSum[n-1]-(long long)(n)*beans[0];
        long long sum=beans[0];
        for(int i=1;i<n;i++){
            long long temp = sum+(prefixSum[n-1]-prefixSum[i-1])-(long long)(n-i)*beans[i];
            sum+=beans[i];
            if(temp<ans)ans=temp;
        }
        if(sum<ans)ans=sum;

        return ans;
    }
};