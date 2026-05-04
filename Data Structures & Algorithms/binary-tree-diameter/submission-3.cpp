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

    int maxDepth(TreeNode* root) 
    {
        if (!root)
            return -1;
        
        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        // depth of left + depth of right
        if (!root)
            return 0;

        int leftDepth = maxDepth(root->left) + 1;
        int rightDepth = maxDepth(root->right) + 1;
        diameters_.insert(leftDepth+rightDepth);
        std::cout << leftDepth << " " << rightDepth << std::endl;


        diameterOfBinaryTree(root->left);  
        diameterOfBinaryTree(root->right);

        return *(--diameters_.end());
    }

    private:
        std::set<int> diameters_;
};
