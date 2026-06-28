class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // Code here
        int m = A.size(), n = B.size(), p = B[0].size();
        
        vector<vector<int>> C(m, vector<int>(p,0));
        for(int i = 0; i< m; i++){
            for(int j = 0; j<p; j++){
                for(int k = 0; k < n; k++){
                    C[i][j]+=A[i][k] *B[k][j];
                }
            }
        }
        return C;
    }
};