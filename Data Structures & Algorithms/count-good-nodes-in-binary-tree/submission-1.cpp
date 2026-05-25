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
    int count = 0;
    std::multiset<int, std::greater<int>> currPath;

    void travers(TreeNode* root)
    {
        if (!root)
            return;
        
        if (currPath.empty() || *(currPath.begin()) <= root->val)
        {
            ++count;
        }

        currPath.insert(root->val);

        travers(root->left);
        travers(root->right);

        auto itToDel = currPath.find(root->val);
        currPath.erase(itToDel);
    }


    int goodNodes(TreeNode* root) 
    {
        travers(root);    

        return count;
    }
};
