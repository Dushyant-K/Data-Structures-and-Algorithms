class Solution {
private:
    long long sumLeft(int mid, int length) {
        // Sum of values decreasing from `mid` to the left
        if (length >= mid) {
            // Use full range until `1`, then pad with zeros
            return (long long)mid * (mid + 1) / 2 + (length - mid);
        } else {
            // Partial range
            int top = mid;
            int bottom = mid - length + 1;
            return (long long)(top + bottom) * length / 2;
        }
    }

    long long sumRight(int mid, int length) {
        // Sum of values decreasing from `mid` to the right
        return sumLeft(mid, length); // Symmetric logic for left and right
    }

    bool isValid(int n, int index, int maxSum, int mid) {
        // Calculate left and right lengths
        int leftLength = index;
        int rightLength = n - index - 1;

        // Compute total sum when `nums[index] = mid`
        long long totalSum = mid;
        totalSum += sumLeft(mid - 1, leftLength);  // Sum to the left
        totalSum += sumRight(mid - 1, rightLength); // Sum to the right

        return totalSum <= maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum, result = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(n, index, maxSum, mid)) {
                result = mid; 
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }

        return result; 
    }
};