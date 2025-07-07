class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int n = events.size();
        int day = 0, i = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        while (i < n || !pq.empty()) {
            if (pq.empty() && i < n)
                day = events[i][0];

            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                ++i;
            }

            while (!pq.empty() && pq.top() < day)
                pq.pop();

            if (!pq.empty()) {
                pq.pop();
                ++ans;
                ++day;
            }
        }

        return ans;
    }
};
