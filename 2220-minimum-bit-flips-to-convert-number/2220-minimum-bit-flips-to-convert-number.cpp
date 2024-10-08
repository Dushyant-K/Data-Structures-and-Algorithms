class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Approach-1
        int bitFlips=0;
        int xor1=start^goal;
        while(xor1>1){
           bitFlips+= (xor1&1);
            xor1=(xor1>>1);
        }
        if(xor1==1)bitFlips++;
        return bitFlips;
    }
};