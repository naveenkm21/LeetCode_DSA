class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move Right across the top row
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down
            
            // 2. Move Down along the right column
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left
            
            // 3. Move Left across the bottom row (if it still exists)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }
            
            // 4. Move Up along the left column (if it still exists)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }
        
        return res;
    }
};