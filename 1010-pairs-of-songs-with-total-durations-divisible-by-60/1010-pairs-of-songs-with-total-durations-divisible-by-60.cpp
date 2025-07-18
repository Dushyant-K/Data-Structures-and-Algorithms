class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //Approach-1(Brute Force Approach)
        // int n = time.size();

        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((time[i]+time[j])%60==0)count++;
        //     }
        // }

        // return count;

        //Approach-2(Using Prefix Sum Approach)
        int n=time.size();

        map<int,int> mpp;
        int count=0;

        for(int i=0;i<n;i++){
            int remainder = time[i]%60;
            int requirement = 60-remainder;

            if(mpp.find(requirement)!=mpp.end())count+=mpp[requirement];

            if(remainder==0)mpp[60]++;
            else mpp[remainder]++;
        }

        return count;
    }
};