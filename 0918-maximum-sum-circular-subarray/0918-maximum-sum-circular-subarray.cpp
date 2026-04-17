#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0, maxSub = nums[0];
        int curMin = 0, minSub = nums[0];

        for (int x : nums) {
            total += x;

            // Kadane for maximum subarray
            curMax = max(x, curMax + x);
            maxSub = max(maxSub, curMax);

            // Kadane variant for minimum subarray
            curMin = min(x, curMin + x);
            minSub = min(minSub, curMin);
        }

        // If all numbers are negative, total == minSub == maxSub
        // In that case, total - minSub would be 0 (empty subarray), which is not allowed.
        if (maxSub < 0) {
            return maxSub;
        }

        // Otherwise, compare non-circular and circular cases
        return max(maxSub, total - minSub);
    }
};