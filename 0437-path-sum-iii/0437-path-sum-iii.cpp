class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSumCount;
        prefixSumCount[0] = 1; // base case for root
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long currSum, int targetSum, unordered_map<long, int>& prefixSumCount) {
        if (!node) return 0;

        currSum += node->val;
        int count = prefixSumCount[currSum - targetSum];

        prefixSumCount[currSum]++;

        count += dfs(node->left, currSum, targetSum, prefixSumCount);
        count += dfs(node->right, currSum, targetSum, prefixSumCount);

        prefixSumCount[currSum]--; // backtrack

        return count;
    }
};
