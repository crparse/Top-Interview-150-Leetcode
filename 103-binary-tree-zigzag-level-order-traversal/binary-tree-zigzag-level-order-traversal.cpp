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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0; // To track the current level
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelData(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                
                // Store node value based on the direction (left to right or right to left)
                int index = (level % 2 == 0) ? i : (size - 1 - i);
                levelData[index] = temp->val;
                
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            
            ans.push_back(levelData);
            ++level; // Move to the next level
        }
        
        return ans;
    }
};
