class Solution {
public:
    int bestClosingTime(string customers) {
        //Approach-1(Prefix Sum Approach)
        int n=customers.size();

        int minHour=n;
        int suffixPenalty=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y')suffixPenalty++;
        }

        int prefixPenalty=0;
        int minPenalty=INT_MAX;
        for(int i=0;i<n;i++){
            int penalty=prefixPenalty+suffixPenalty;
            if(customers[i]=='Y'){
                suffixPenalty--;
            }else{
                prefixPenalty++;
            }
            if(penalty<minPenalty){
                minPenalty=penalty;
                minHour=i;
            }
        }

        int penalty=prefixPenalty+suffixPenalty;
        if(penalty<minPenalty){
            minPenalty=penalty;
            return n;
         }
            return minHour;
    }
};