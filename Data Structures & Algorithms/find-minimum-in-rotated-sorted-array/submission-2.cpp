class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        // log(n)
        if (nums.size() == 1)
            return nums[0];
        
        if (nums[0] < nums.back())
            return nums[0];

        int l = 0;
        int r = nums.size()-1;
        int res = 0;

        while (l < r)
        {
            int m = l+(r-l)/2;

            if (nums[m] < nums[r])
            {
                r = m;
            }
            else
            {
                l = m + 1;  
            }
        }

        return nums[l];
    }
};
