#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
     
        unordered_map<string, vector<string>> graph;
        
        unordered_map<string, int> indegree;
        
        for (int i = 0; i < recipes.size(); ++i) {
            string recipe = recipes[i];
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipe);
            }
            indegree[recipe] = ingredients[i].size();
        }
        
        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }
        
        vector<string> result;
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            if (graph.find(current) != graph.end()) {
                for (const string& recipe : graph[current]) {
                    indegree[recipe]--;
                    
                    if (indegree[recipe] == 0) {
                        q.push(recipe);   
                        result.push_back(recipe); 
                    }
                }
            }
        }
        
        return result;
    }
};
