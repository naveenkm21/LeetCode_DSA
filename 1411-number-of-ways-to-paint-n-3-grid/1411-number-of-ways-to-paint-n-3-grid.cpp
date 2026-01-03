class Solution {
public:
    int numOfWays(int n) {
        const long MOD = 1000000007;
        long waysA = 6; // ABA patterns
        long waysB = 6; // ABC patterns

        for (int i = 2; i <= n; ++i) {
            long newA = (3 * waysA + 2 * waysB) % MOD;
            long newB = (2 * waysA + 2 * waysB) % MOD;
            waysA = newA;
            waysB = newB;
        }

        return (waysA + waysB) % MOD;
    }
};
