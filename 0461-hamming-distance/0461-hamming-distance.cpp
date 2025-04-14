class Solution {
public:
    int hammingDistance(int x, int y) {
        //Approach-1(Using Xor)
        int num = x^y;

        int distance=0;
        while(num>0){
            if(num&1)distance++;
            num=num>>1;
        }

        return distance;
    }
};