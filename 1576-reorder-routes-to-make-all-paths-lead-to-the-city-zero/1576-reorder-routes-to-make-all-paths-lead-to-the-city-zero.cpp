class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n); // (neighbor, direction)
        for (auto& conn : connections) {
            graph[conn[0]].push_back({conn[1], 1});  // 1 means original direction u -> v
            graph[conn[1]].push_back({conn[0], 0});  // 0 means reversed (v <- u)
        }

        vector<bool> visited(n, false);
        int changes = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto& [neighbor, direction] : graph[node]) {
                if (!visited[neighbor]) {
                    if (direction == 1) changes++; 
                    dfs(neighbor);
                }
            }
        };

        dfs(0);
        return changes;
    }
};
