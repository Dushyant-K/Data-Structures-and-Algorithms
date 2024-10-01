class Solution {
public:
    string removeOuterParentheses(string s) {
      //Approach-1
      int count=0;
      string result="";
      for(auto ch:s){
        if(ch=='('){
            if(count>0)result+=ch;
            count++;
        }
        else{
            count--;
            if(count>0)result+=ch;
        }
      }
      return result;
    }
};