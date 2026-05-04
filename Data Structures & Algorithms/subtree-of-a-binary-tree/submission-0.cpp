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
    bool isSame(TreeNode* rt1, TreeNode* rt2)
    {
        if (!rt1 && !rt2)
            return true;
        
        if (!rt1 || !rt2 || rt1->val != rt2->val)
            return false;

        
        return isSame(rt1->left, rt2->left) && isSame(rt1->right, rt2->right);     
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       // traverse all root
       // if node == subRoot -> check if other nodes are the same after that point

        if (!root) // the first node of subRoot cant be nullptr
            return false;
        
        if (root->val == subRoot->val && isSame(root, subRoot))
        {
            return true;
        }

        if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
            return true;    
        
        return false;
    }
};
