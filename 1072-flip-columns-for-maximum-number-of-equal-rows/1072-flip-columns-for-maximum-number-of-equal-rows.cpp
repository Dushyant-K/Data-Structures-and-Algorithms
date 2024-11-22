class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //Approach-1(New Strategy)
        unordered_map<string,int> mpp;
        for(auto it:matrix){
            string str="";
            int firstElement=it[0];
            for(int i=1;i<it.size();i++){
                if(it[i]!=firstElement)str+="0";
                else str+="1";
            }
            mpp[str]++;
        }
        int maxCount=0;
        for(auto it:mpp){
            maxCount=max(maxCount,it.second);
        }
        return maxCount;

    }
};