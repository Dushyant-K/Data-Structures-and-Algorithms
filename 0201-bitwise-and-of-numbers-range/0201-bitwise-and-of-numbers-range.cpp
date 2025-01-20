class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    //Approach-1(Bit Manipulation)
    int shift = 0; // Count the number of right shifts
    // Find the common prefix of left and right
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    // Shift the common prefix back to its original position
    return left << shift;
    }
};