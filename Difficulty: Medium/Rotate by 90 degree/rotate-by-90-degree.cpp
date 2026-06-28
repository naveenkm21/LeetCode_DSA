class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // 1. Reverse each row first
        for(auto& row : mat) {
            reverse(row.begin(), row.end());
        }
        
        // 2. Then Transpose
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
};