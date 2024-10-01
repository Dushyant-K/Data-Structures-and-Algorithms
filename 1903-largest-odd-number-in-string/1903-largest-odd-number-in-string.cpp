class Solution {
public:
    string largestOddNumber(string num) {
        int index=-1;
        for(int i=num.size()-1;i>=0;i--){
            int no = num[i]-'0';
            if(no%2==1){
                index=i;
                break;
            }
        }
        if(index==-1)return "";
        string result="";
        for(int i=0;i<=index;i++){
            result+=num[i];
        }
        return result;
    }
};