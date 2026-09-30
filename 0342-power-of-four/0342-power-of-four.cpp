class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};

    // 1. n must be strictly positive.
        // 2. (n & (n - 1)) == 0 checks if n is a power of 2 (has exactly one set bit).
        // 3. (n & 0x55555555) != 0 ensures the single set bit is at an even position.