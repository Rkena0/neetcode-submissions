class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        for (int i = 0; i< nums.size(); ++i)
        {
            int curr = nums[i];
            if (nums[std::abs(curr)] < 0)
                return std::abs(curr);
            
            nums[std::abs(curr)] *= -1;
        }

        return 0;
    }
};
