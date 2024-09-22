class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
        int n = x;
        while(n>0){
            int digit = n%10;
            n = n/10;
            if(rev>INT_MAX/10||rev==INT_MAX/10&&digit<7)return 0;

            if(rev<INT_MIN/10||rev==INT_MIN/10&&digit<-8)return 0;

            rev = rev*10+digit;
        }
        if(x==rev)return true;
        return false;
    }
};