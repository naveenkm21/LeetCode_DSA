#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> visited(n + 1, 0);
        return dfs(1, -1, t, target, 1.0, g);
    }

private:
    double dfs(int u, int parent, int t, int target, double prob,
               const vector<vector<int>>& g) {
        int choices = 0;
        for (int v : g[u]) {
            if (v != parent) ++choices;
        }

        if (t == 0) {
     
            return (u == target) ? prob : 0.0;
        }

        if (u == target) {
     
            return (choices == 0) ? prob : 0.0;
        }

        if (choices == 0) {
         
            return 0.0;
        }

        double res = 0.0;
        double nextProb = prob / choices;
        for (int v : g[u]) {
            if (v == parent) continue;
            res += dfs(v, u, t - 1, target, nextProb, g);
        }
        return res;
    }
};
