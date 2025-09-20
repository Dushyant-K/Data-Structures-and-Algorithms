class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // handle zero + negatives
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if (n & (1u << i)) count++;   // use unsigned to avoid UB
            if (count > 1) return false;
        }
        return true;
    }
};
