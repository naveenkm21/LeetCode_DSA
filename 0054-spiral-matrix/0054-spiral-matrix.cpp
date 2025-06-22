class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> res;
        int top = 0, bottom = m.size()-1, left = 0, right = m[0].size()-1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) res.push_back(m[top][i]);
            top++;
            for (int i = top; i <= bottom; i++) res.push_back(m[i][right]);
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; i--) res.push_back(m[bottom][i]);
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; i--) res.push_back(m[i][left]);
            left++;
        }
        return res;
    }
};