// User function Template for C++

class Solution {
    private:
    void generateAllBinaryString(string str, vector<string>& ans, int n){
        if(str.length()==n){
            ans.push_back(str);
            return ;
        }
        
        //Adding 0 to the string
        generateAllBinaryString(str+"0",ans,n);
        //Adding 1 to the string
        if(str.empty()||str.back()=='0')
        generateAllBinaryString(str+"1",ans,n);
    }
  public:
    vector<string> generateBinaryStrings(int num) {
        //Approach-1
        string str="";
        vector<string> ans;
        
        generateAllBinaryString(str,ans,num);
        
        return ans;
    }
};