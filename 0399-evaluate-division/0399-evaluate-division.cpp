class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end()) return -1.0;
        if (curr == target) return 1.0;
        
        visited.insert(curr);
        for (auto& [neighbor, weight] : graph[curr]) {
            if (visited.count(neighbor)) continue;
            double product = dfs(neighbor, target, graph, visited);
            if (product != -1.0)
                return product * weight;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].emplace_back(b, val);
            graph[b].emplace_back(a, 1.0 / val);
        }

        vector<double> res;
        for (auto& query : queries) {
            string src = query[0], dst = query[1];
            unordered_set<string> visited;
            double result = dfs(src, dst, graph, visited);
            res.push_back(result);
        }

        return res;
    }
};
