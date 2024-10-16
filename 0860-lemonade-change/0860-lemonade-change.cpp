class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //Approach-1
        int countFive=0;
        int countTen=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                countFive++;
            }
            else if(bills[i]==10){
                if(countFive==0)return false;
                countFive--;
                countTen++;
            }
            else{
                if(countFive>=1&&countTen>=1){
                    countFive = countFive-1;
                    countTen = countTen-1;
                }
                else if(countFive>=3){
                    countFive-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};