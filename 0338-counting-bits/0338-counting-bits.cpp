class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitCounts(n + 1);
        for (int num = 0; num <= n; ++num) {
            bitCounts[num] = __builtin_popcount(num);
        }

        return bitCounts; 
    }
};
