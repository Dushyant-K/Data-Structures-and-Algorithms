class Solution {
public:
    bool checkParanthesis(string s, int idx, int count){
        if(count<0)return false;
        if(idx==s.size())return (count==0);

        if(s[idx]=='('){
            return (checkParanthesis(s,idx+1,count+1));
        }

        else if(s[idx]==')'){
            return (checkParanthesis(s,idx+1,count-1));
        }
        else
        return  (checkParanthesis(s,idx+1,count+1)||checkParanthesis(s,idx+1,count-1)||   checkParanthesis(s,idx+1,count));
    } 
    bool checkValidString(string s) {
        //Approach1
        return (checkParanthesis(s,0,0));
    }
};