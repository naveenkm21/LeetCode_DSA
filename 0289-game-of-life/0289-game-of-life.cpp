class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        // First pass: mark transitions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (auto& [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1)
                        live++;
                }

                // Apply rules using temporary states
                if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = -1;  // Alive → Dead
                if (board[i][j] == 0 && live == 3)
                    board[i][j] = 2;   // Dead → Alive
            }
        }

        // Second pass: finalize values
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = board[i][j] > 0 ? 1 : 0;
    }
};
