#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            // Either extend the previous subarray or start new at nums[i]
            current_sum = max(nums[i], current_sum + nums[i]);
            // Update global maximum
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};