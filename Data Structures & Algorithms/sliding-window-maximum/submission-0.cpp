class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        std::map<int, int, std::greater<int>> max;
        for (int i = 0; i < k; ++i)
        {
            ++max[nums[i]];
        }

        std::vector<int> res;
        res.push_back(max.begin()->first);

        for (int i = 0; i < nums.size() - k; ++i)
        {
            --max[nums[i]];
            if (max[nums[i]] == 0)
                max.erase(nums[i]);
            
            ++max[nums[i+k]];

            res.push_back(max.begin()->first);
        }

        return res;
    }
};
