class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        std::vector<int> pre;
        std::vector<int> suff;

        int currPre = 1;
        int currSuff = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            currPre *= nums[i];
            currSuff *= nums[nums.size() - 1 - i];

            pre.push_back(currPre);
            suff.push_back(currSuff);
        }

        std::vector<int> res;
        res.push_back(suff[nums.size() - 2]);
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            res.push_back(pre[i-1]*suff[nums.size() - 2 - i]);
        }
        res.push_back(pre[nums.size() - 2]);

        return res;
    }
};
