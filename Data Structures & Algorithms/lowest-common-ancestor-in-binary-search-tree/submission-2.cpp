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
    std::vector<TreeNode*> ancs1, ancs2;

    std::vector<TreeNode*> travers(TreeNode* root, TreeNode* curr, std::vector<TreeNode*> path)
    {
        if (root == nullptr)
            return path;
        
        path.push_back(root);
        if (root == curr)
        {
            return path;
        }

        if (curr->val <= root->val)
            return travers(root->left, curr, path);
        else
            return travers(root->right, curr, path);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancs1.clear();
        ancs2.clear();

        ancs1 = travers(root, p, {});
        ancs2 = travers(root, q, {});

        TreeNode* res = nullptr;
        int minSize = std::min(ancs1.size(), ancs2.size());

        for (int i = 0; i < minSize; ++i)
        {
            if (ancs2[i] == ancs1[i])
                res = ancs1[i];
            else 
                break;
        }

        return res;
    }
};
