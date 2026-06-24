class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n, -1);

        stack<int> st; // stores indices

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[i] > arr[st.top()]) {

                int idx = st.top();
                st.pop();

                ans[idx] = arr[i];
            }

            st.push(i);
        }

        return ans;
    }
};