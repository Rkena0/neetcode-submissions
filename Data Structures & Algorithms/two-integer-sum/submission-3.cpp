class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int toFind = target - nums[i];

            auto it = std::find(nums.begin() + i + 1, nums.end(), toFind);
            if (it != nums.end())
                return {i, int(it - nums.begin())};
        }

        return {};
    }
};
