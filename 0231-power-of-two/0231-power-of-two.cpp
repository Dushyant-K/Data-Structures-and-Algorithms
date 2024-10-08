class Solution {
public:
    bool isPowerOfTwo(int n) {
     int count=0;
     while(n>1){
        if(n%2==1)count++;
        n=n/2;
     }
     if(n==1)count++;
     if(count==1)return true;
     return false;
    }
};