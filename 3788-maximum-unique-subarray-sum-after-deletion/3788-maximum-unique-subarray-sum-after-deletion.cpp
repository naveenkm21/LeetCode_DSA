#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());

        if (mx <= 0)
            return mx;

        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        int sum = 0;
        for (int num : numsSet) {
            if (num > 0) {
                sum += num;
            }
        }

        return sum;
    }
};
