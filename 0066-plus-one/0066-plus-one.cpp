class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         int n = digits.size();

    // Traverse the digits array from the last digit to the first
    for (int i = n - 1; i >= 0; --i) {
        // If the digit is less than 9, just increment and return the result
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        // If the digit is 9, set it to 0 and continue the loop
        digits[i] = 0;
    }

    // If all the digits were 9, we need to add a new leading 1
    digits.insert(digits.begin(), 1);

    return digits;
    }
};