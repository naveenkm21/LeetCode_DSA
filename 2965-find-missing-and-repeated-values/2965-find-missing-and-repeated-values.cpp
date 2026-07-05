class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalElements = n * n;
        vector<int> count(totalElements + 1, 0);
        
        int repeated = -1;
        int missing = -1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                count[grid[i][j]]++;
            }
        }
        
        for (int i = 1; i <= totalElements; ++i) {
            if (count[i] == 2) {
                repeated = i;
            } else if (count[i] == 0) {
                missing = i;
            }
            
            if (repeated != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeated, missing};
    }
};