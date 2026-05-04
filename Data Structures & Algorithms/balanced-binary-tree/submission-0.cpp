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
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        
        return std::max(height(root->left)+1, height(root->right)+1);
    }

    bool isBalanced(TreeNode* root) 
    {
        if (!root)
            return true;

        int leftHeight = height(root->left)+1;
        int rightHeight = height(root->right)+1;
        if (std::abs(leftHeight-rightHeight) > 1)
            return false;

        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;

        return true;
    }
};
