class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        std::set<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i+1;
            int r  = nums.size()-1;
            
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                    res.insert({nums[i], nums[l], nums[r]});

                if (nums[i] + nums[l] + nums[r] > 0)
                    --r;
                else
                    ++l;
            }
        }

        vector<vector<int>> resVec(res.begin(), res.end());
        return resVec;
    }
};
