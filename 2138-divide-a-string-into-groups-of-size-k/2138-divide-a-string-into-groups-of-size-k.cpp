class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        //Approach-1
        int n = s.length();
        vector<string> ans;
        for(int i=0;i<n;i+=k){
            string str="";
            if(n-i>=k){
                str+=s.substr(i,k);
            }else{
                str+=s.substr(i,n-i);
                  while (str.length() < k) {
                str += fill;
            }
            }

            ans.push_back(str);
        }

        return ans;
    }
};