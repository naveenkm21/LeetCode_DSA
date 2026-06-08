class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            totalSum += mat[i][i];
            
            if (i != n - 1 - i) {
                totalSum += mat[i][n - 1 - i];
            }
        }
        
        return totalSum;
    }
};