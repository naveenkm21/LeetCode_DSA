class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check n is positive, is a power of two, and its single '1' bit is in an odd position
        return n > 0 &&
               (n & (n - 1)) == 0 &&        // power of two
               (n & 0x55555555) != 0;       // bit in odd position (1, 4, 16, ...)
    }
};
