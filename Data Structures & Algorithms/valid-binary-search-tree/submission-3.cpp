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
    bool isBST(TreeNode* root, int currMax, int currMin)
    {
        if (!root)
            return true;

        if (root->val >= currMax || root->val <= currMin)
            return false;

        return isBST(root->left, root->val, currMin) && isBST(root->right, currMax, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, 1001, -1001);
    }
};
