// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // Approach-1
        int sum=0;
        
        int number = n;
        
        while(number>0){
            int digit = number%10;
            sum+=digit*digit*digit;
            
            number=number/10;
        }
        
        if(sum==n)return true;
        return false;
        
    }
};