class BSTIterator {
private:
    stack<TreeNode*> stk;

    // Helper to push all left nodes from current to the leftmost
    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    // Constructor: push all left children from root
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // Return the next smallest element
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
    
    // Check if there's a next element
    bool hasNext() {
        return !stk.empty();
    }
};
