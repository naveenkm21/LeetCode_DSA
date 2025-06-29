class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;

        int count = 0;
        if (node->val >= maxSoFar) {
            count = 1;
        }

        maxSoFar = max(maxSoFar, node->val);
        count += dfs(node->left, maxSoFar);
        count += dfs(node->right, maxSoFar);
        return count;
    }
};
