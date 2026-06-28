class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> result(n, vector<int>(m));
        
        for(int r = 0; r<m ; r++){
            for(int c = 0; c<n; c++){
                result[c][r] = mat[r][c];
            }
        }
        return result;
    }
};