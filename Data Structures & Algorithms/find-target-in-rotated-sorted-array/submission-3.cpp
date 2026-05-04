class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;

        while (l < r)
        {
            int m = l+(r-l)/2;

            if (nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }

        // now l is start of rotated or 0 if not rotated
        int l1;
        int r1;
        
        if (target > nums.back())
        {
            l1 = 0;
            r1 = l;
        }
        else
        {
            l1 = l;
            r1 = nums.size()-1;
        }

        //std::cout << "l1: " << l1 << std::endl;
        //std::cout << "r1: " << r1 << std::endl;

        while (l1 <= r1)
        {
            int m = l1+(r1-l1)/2;

            if (target == nums[m])
                return m;

            if (target > nums[m])
                l1 = m + 1;
            else
                r1 = m - 1;
        }

        return -1;
    }
};
