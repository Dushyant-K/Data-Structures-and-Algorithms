class Solution {
public:
    long long modExp(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        //Approach-1
        int mod = (1e9+7);
        long long evenPosCount = (n + 1) / 2; // counts 5's
        long long oddPosCount = n / 2;        // counts 4's

        long long count5 = modExp(5, evenPosCount, mod);
        long long count4 = modExp(4, oddPosCount, mod);

        return (count5 * count4) % mod;
    }
};