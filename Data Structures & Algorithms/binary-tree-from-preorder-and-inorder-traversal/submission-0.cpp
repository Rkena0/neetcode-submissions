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
    int currPreI_ = 0;
    std::unordered_map<int, int> inVal2Indx_;

    void travers(TreeNode*& root, int l, int r, const vector<int>& preorder)
    {
        if (currPreI_ >= preorder.size())
            return;

        if (l >= r)
            return;
        
        std::cout << "currPreI_: " << currPreI_ << std::endl;
        int currVal = preorder[currPreI_++];
        root = new TreeNode(currVal);

        travers(root->left, l, inVal2Indx_[currVal], preorder);
        travers(root->right, inVal2Indx_[currVal] + 1, r, preorder);        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
        {
            inVal2Indx_[inorder[i]] = i;
        }

        TreeNode* res;
        
        travers(res, 0, preorder.size(), preorder);

        return res;
    }
};
