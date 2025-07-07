class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inIndex;
        for (int i = 0; i < inorder.size(); ++i)
            inIndex[inorder[i]] = i;

        int postIdx = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1, postIdx, inIndex);
    }

private:
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder,
                    int inLeft, int inRight, int& postIdx,
                    unordered_map<int, int>& inIndex) {
        if (inLeft > inRight)
            return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int inRootIdx = inIndex[rootVal];

        root->right = build(inorder, postorder, inRootIdx + 1, inRight, postIdx, inIndex);
        root->left  = build(inorder, postorder, inLeft, inRootIdx - 1, postIdx, inIndex);

        return root;
    }
};
