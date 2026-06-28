class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> res;
        if (mat.empty() || mat[0].empty()) return res; // Good safety check
        
        int top = 0, bottom = mat.size() - 1;       // Fixed: m -> mat
        int left = 0, right = mat[0].size() - 1;     // Fixed: m -> mat
        
        while (top <= bottom && left <= right) {
            // 1. Left to Right
            for (int j = left; j <= right; j++) res.push_back(mat[top][j]);
            top++;
            
            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++) res.push_back(mat[i][right]);
            right--;
            
            // 3. Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) res.push_back(mat[bottom][j]);
                bottom--;
            }
            
            // 4. Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) res.push_back(mat[i][left]);
                left++;
            }
        }
        return res;
    }
};