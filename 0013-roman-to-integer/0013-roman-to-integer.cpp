class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int n = s.length();

    // Iterate over the Roman numeral string
    for (int i = 0; i < n; ++i) {
        // Get the value of the current symbol
        int current_value = roman_to_int[s[i]];

        // If the current value is less than the value of the next symbol, subtract it
        if (i + 1 < n && current_value < roman_to_int[s[i + 1]]) {
            total -= current_value;
        } else {
            total += current_value;
        }
    }

    return total;
    }
};