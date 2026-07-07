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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {  
        if (!root)
            return "";

        std::vector<int> dataVec;
        dataVec.push_back(root->val);
        treeToVec(root, dataVec);
        
        while(!dataVec.empty() && dataVec.back() == INT_MIN)
        {
            dataVec.pop_back();
        }

        std::string serializeStr;
        convertVecToStr(dataVec, serializeStr);

        return serializeStr;
    }

    void treeToVec(TreeNode* root, std::vector<int>& dataVec)
    {
        if (!root)
        {
            return;
        }
        
        if (root->left)
            dataVec.push_back(root->left->val);
        else
            dataVec.push_back(INT_MIN);

        if (root->right)
            dataVec.push_back(root->right->val);
        else
            dataVec.push_back(INT_MIN);

        treeToVec(root->left, dataVec);
        treeToVec(root->right, dataVec);
    }

    void convertVecToStr(const std::vector<int>& dataVec, std::string& serializeStr)
    {
        std::stringstream ss;
        for (int i = 0; i < dataVec.size(); ++i)
        {
            if (i != 0)
                ss << ",";

            if (dataVec[i] == INT_MIN)
            {
                ss << "n";
            }
            else
            {
                std::string numStr = std::to_string(dataVec[i]);
                ss << numStr;
            }
        }

        serializeStr = ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        std::vector<int> dataVec = convertStringTreeToVec(data);

        TreeNode* root = new TreeNode(dataVec[0]);
        int indx = 1;
        createTreeRec(root, dataVec, indx);

        return root;
    }
    
    std::vector<int> convertStringTreeToVec(const std::string& data)
    {
        // "," "-111" "n" 
        std::stringstream ss(data);
        std::string currStr;

        std::vector<int> dataVec;
        while (std::getline(ss, currStr, ','))
        {
            if (currStr == "n")
                dataVec.push_back(INT_MIN);
            else
            {
                int num = std::stoi(currStr);
                dataVec.push_back(num);
            }
        }

        return dataVec;
    }

    void createTreeRec(TreeNode*& root, const std::vector<int>& dataVec, int& indx)
    {
        if (indx >= dataVec.size())
            return;

        if (indx < dataVec.size() && dataVec[indx] != INT_MIN)
            root->left = new TreeNode(dataVec[indx]);
        ++indx;

        if (indx < dataVec.size() && dataVec[indx] != INT_MIN)
            root->right = new TreeNode(dataVec[indx]);
        ++indx;
        
        if (root->left)
            createTreeRec(root->left, dataVec, indx);
        
        if (root->right)
            createTreeRec(root->right, dataVec, indx);
    }
};
