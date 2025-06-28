class Solution {
public:
    int mySqrt(int n) {
        //Approach-1(Using Binary Search)
         int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = low+(high-low)/2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
    }
};