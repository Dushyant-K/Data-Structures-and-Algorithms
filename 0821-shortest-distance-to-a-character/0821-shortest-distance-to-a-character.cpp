class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        //Approach-1(hashing)
        int n = s.size();
        vector<int> answer(n, INT_MAX);

        // First pass: calculate distance from left to right
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                prev = i;
            }
            if (prev != -1) {
                answer[i] = abs(i - prev);
            }
        }

        // Second pass: calculate distance from right to left
        prev = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                prev = i;
            }
            if (prev != -1) {
                answer[i] = min(answer[i], abs(i - prev));
            }
        }

        return answer;
    }
};