class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int l = 0;
        int r = heights.size()-1;

        int max = 0;
        while (l < r)
        {
            int curr = (r-l) * std::min(heights[l], heights[r]);
            max = std::max(max, curr);

            if (heights[l] > heights[r])
                --r;
            else
                ++l;
        }

        return max;
    }
};
