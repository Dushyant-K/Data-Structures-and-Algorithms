class Solution {
    private:
    void getAllPartitions(int idx, string s, vector<string>& ds, vector<vector<string>>& ans){
        if(idx==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(idx,i,s)){
                ds.push_back(s.substr(idx,i-idx+1));
                getAllPartitions(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(int low, int high, string s){
        while(low<=high){
            if(s[low]!=s[high])return false;
            low++;
            high--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        //Approach-1
        vector<string> ds;
        vector<vector<string>> ans;
        getAllPartitions(0,s,ds,ans);
        return ans;
    }
};