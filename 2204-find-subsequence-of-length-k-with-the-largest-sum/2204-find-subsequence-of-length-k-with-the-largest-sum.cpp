class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i)
            v.emplace_back(nums[i], i);
        sort(v.rbegin(), v.rend());
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(v[i].second);
        sort(res.begin(), res.end());
        for (int i = 0; i < k; ++i)
            res[i] = nums[res[i]];
        return res;
    }
};
