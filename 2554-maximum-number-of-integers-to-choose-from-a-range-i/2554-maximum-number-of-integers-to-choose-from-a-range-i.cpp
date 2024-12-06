class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        //Approach-1
        if(maxSum==0)return 0;
        unordered_set<int> st;
        for(int i=0;i<banned.size();i++){
            st.insert(banned[i]);
        }
        int count=0;
        int i=1;
        while(maxSum>0&&i<=n){
            if(st.find(i)==st.end()&&maxSum-i>=0){
                maxSum-=i;
                count++;
            }
            i++;
        }
        return count;
    }
};