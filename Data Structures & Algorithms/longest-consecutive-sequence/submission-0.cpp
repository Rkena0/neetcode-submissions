class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res = 0;

        std::unordered_set<int> exist;
        for (int i = 0; i < nums.size(); ++i)
        {
            exist.insert(nums[i]);
        }

        std::unordered_set<int> cands;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (exist.count(nums[i]-1) == 0)
            {
                cands.insert(nums[i]);
            }
        }

        int curr = 1;
        for (auto i : cands)
        {   
            int currEll = i+1;
            while (exist.count(currEll++) > 0)
                ++curr;
            
            res = std::max(res, curr);
            curr = 1;
        }

        return res;
    }
};
