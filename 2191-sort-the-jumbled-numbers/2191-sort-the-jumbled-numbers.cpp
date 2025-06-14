class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate_integer = [&](int num) -> int {
            if (num == 0) {
                return mapping[0];
            }
            int res = 0;
            int cur_mult = 1;
            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                res += mapping[digit] * cur_mult;
                cur_mult *= 10;
            }
            return res;
        };

        unordered_map<int, int> number_mapping;
        for (int num : nums) {
            if (number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });

        return nums;
    }
};