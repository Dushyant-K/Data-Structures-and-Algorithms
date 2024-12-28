class Solution {
    const int mod = 1000000007; // Use exact integer constant

    // Modular multiplication to avoid overflow
    long long safeMul(long long a, long long b, long long mod) {
        long long result = 0;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result + a) % mod;
            }
            a = (a * 2) % mod;
            b /= 2;
        }
        return result;
    }

    // Modular exponentiation function
    long long modExp(long long val, long long pow, long long mod) {
        long long result = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                result = safeMul(result, val, mod); // Use safe multiplication
            }
            val = safeMul(val, val, mod);         // Use safe multiplication
            pow /= 2;
        }
        return result;
    }

public:
    int minNonZeroProduct(int p) {
        // The maximum value in the range [1, 2^p - 1]
        long long maxVal = (1LL << p) - 1; // 2^p - 1

        // Calculate (maxVal - 1)^(maxVal/2) % MOD
        long long part1 = modExp(maxVal - 1, maxVal / 2, mod);

        // Multiply part1 with maxVal and take modulo MOD
        long long result = safeMul(part1, maxVal % mod, mod);

        return static_cast<int>(result); // Return result as int
    }
};
