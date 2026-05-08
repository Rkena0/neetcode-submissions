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

    void travers(TreeNode* root, vector<vector<int>>& res, int level)
    {
        if (root == nullptr)
            return;
        
        if (res.size() < level+1)
            res.push_back({root->val});
        else
            res[level].push_back(root->val);
        
        travers(root->left, res, level+1);
        travers(root->right, res, level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;

        travers(root, res, 0);

        return res;
    }
};
