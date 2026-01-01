class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //Approach-1
        int n = digits.size();

        int i=n-1;
        while(i>=0){
            if(digits[i]+1<10){
                digits[i]=digits[i]+1;
                break;
            }else{
                digits[i]=0;
            }
            i--;
        }

        if(i==-1)digits.insert(digits.begin(),1);

        return digits;
    }
};