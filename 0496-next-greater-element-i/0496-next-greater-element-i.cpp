class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;       

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int cur = nums2[i];

            while (!st.empty() && st.top() <= cur) {
                st.pop();
            }

            nextGreater[cur] = st.empty() ? -1 : st.top();

            st.push(cur);
        }

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) {
            ans.push_back(nextGreater[x]);
        }
        return ans;
    }
};
