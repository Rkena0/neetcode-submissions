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
    std::vector<std::vector<int>> perLvl;

    void traverse(TreeNode* root, int lvl)
    {
        if (!root)
            return;
        
        if (perLvl.size() < lvl+1)
            perLvl.push_back({});
        
        perLvl[lvl].push_back(root->val);

        traverse(root->left, lvl+1);
        traverse(root->right, lvl+1);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> res;
        traverse(root, 0);

        for (auto& vec : perLvl)
        {
            res.push_back(vec.back());
        }

        return res;
    }
};
