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
    std::vector<int> sorted;

    void travers(TreeNode* root, int k)
    {
        if (!root)
        {
            return;
        }

        if (root->left)
            travers(root->left, k);

        sorted.push_back(root->val);
        if (sorted.size() == k)
        {
            return;
        }

        if (root->right)
            travers(root->right, k);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        travers(root, k);

        return sorted[k-1];        
    }
};
