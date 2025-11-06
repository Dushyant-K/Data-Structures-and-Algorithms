class Solution {
public:
    int myAtoi(string s) {
        //Approach-1
    int i = 0;
    int n = s.length();
    // Step 1: Ignore leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Step 2: Check if the next character is a sign
    int sign = 1; // Assume the number is positive
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') {
            sign = -1; // Negative number
        }
        i++;
    }

    // Step 3: Convert the digits to integer
    long long result = 0; // Use long long to handle overflow
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        // Step 4: Handle overflow
        if (result * sign > INT_MAX) {
            return INT_MAX;
        }
        if (result * sign < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }

    // Step 5: Return the final result with the correct sign
    return (int)(result * sign);

    }
};