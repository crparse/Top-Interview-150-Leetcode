/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
public:
    int startp=0;
    TreeNode*construct(vector<int>& preorder, vector<int>& inorder,int starti,int endi){
        if(starti>endi) return NULL;
        
        TreeNode*root=new TreeNode(preorder[startp++]);
        int k=0;
        for(int i=starti;i<=endi;i++){
            if(inorder[i]==root->val){
                k=i;
                break;
             }
        }
        root->left=construct(preorder,inorder, starti,k-1);
         root->right=construct(preorder,inorder, k+1, endi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n<=0) return NULL;
        return construct(preorder,inorder,0,n-1);
    }
};

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int, int> inorderIndexMap;
//         for (int i = 0; i < inorder.size(); ++i) {
//             inorderIndexMap[inorder[i]] = i;
//         }
//         return constructTree(preorder, inorder, 0, 0, inorder.size() - 1, inorderIndexMap);
//     }
    
//     TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
//         if (preStart >= preorder.size() || inStart > inEnd) {
//             return nullptr;
//         }
        
//         TreeNode* root = new TreeNode(preorder[preStart]);
//         int inorderIndexRoot = inorderIndexMap[preorder[preStart]];
        
//         root->left = constructTree(preorder, inorder, preStart + 1, inStart, inorderIndexRoot - 1, inorderIndexMap);
//         root->right = constructTree(preorder, inorder, preStart + inorderIndexRoot - inStart + 1, inorderIndexRoot + 1, inEnd, inorderIndexMap);
        
//         return root;
//     }
// };