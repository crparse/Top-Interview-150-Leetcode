/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL or if it's one of the nodes p or q, return root
        if (root == NULL || root == p || root == q) return root;
        
        
        // Recursively find LCA in left and right subtrees
        TreeNode* leftSubtreeLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubtreeLCA = lowestCommonAncestor(root->right, p, q);
        
        // If both leftSubtreeLCA and rightSubtreeLCA are not NULL, it means p and q are found in different subtrees
        // Hence, the current root is the LCA
        if (leftSubtreeLCA && rightSubtreeLCA) return root;
        
        
        // Otherwise, return whichever is not NULL
        return (leftSubtreeLCA != NULL) ? leftSubtreeLCA : rightSubtreeLCA;
    }
};
