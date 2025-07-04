# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index_map = {val: idx for idx, val in enumerate(inorder)}
        n = len(preorder)
        
        def helper(preStart, inStart, inEnd):
            if inStart > inEnd:
                return None
            root_val = preorder[preStart]
            root = TreeNode(root_val)
            idx = index_map[root_val]
            left_size = idx - inStart
            root.left = helper(preStart + 1, inStart, idx - 1)
            root.right = helper(preStart + 1 + left_size, idx + 1, inEnd)
            return root
        
        return helper(0, 0, n - 1)