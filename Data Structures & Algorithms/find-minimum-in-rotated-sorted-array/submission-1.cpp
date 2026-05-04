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

        while (l <= r)
        {
            int m = (r+l)/2;

            if (m > 0 && nums[m-1] > nums[m])
            {
                return nums[m];
            }

            if (m < nums.size()-1 && nums[m] > nums[m+1])
            {
                return nums[m+1];
            }

            if (nums[m] > nums[0])
            {
                l = m+1;
            }
            else
            {
                r = m - 1;  
            }
        }

        
        return nums[0];
    }
};
