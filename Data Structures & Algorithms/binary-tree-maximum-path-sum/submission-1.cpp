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
    int max = INT_MIN;

    int travers(TreeNode* root)
    {
        if (!root)
            return 0;

        int leftSum = travers(root->left);
        int rightSum = travers(root->right);

        int currVal = root->val;
        int currMax = currVal;
        currMax = std::max(currMax, currVal+leftSum);
        currMax = std::max(currMax, currVal+rightSum);

        std::cout << "root->val: " << root->val << std::endl;
        std::cout << "currMax: " << currMax << std::endl;

        max = std::max(max, currMax);
        max = std::max(max, currVal+leftSum+rightSum);

        return currMax;
    }

    int maxPathSum(TreeNode* root) {
        travers(root);

        return max;
    }
};
