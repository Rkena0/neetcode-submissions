class Solution {
public:
    int trap(vector<int>& height) 
    {
        std::vector<int> maxL;
        std::vector<int> maxR;

        int currMaxL = height[0];
        for (int i = 1; i < height.size() - 1; ++i)
        {
            maxL.push_back(currMaxL);

            currMaxL = std::max(currMaxL, height[i]);
        }

        int currMaxR = height.back();
        for (int i = height.size() - 2; i > 0 ; --i)
        {
            maxR.push_back(currMaxR);

            currMaxR = std::max(currMaxR, height[i]);
        }
        std::reverse(maxR.begin(), maxR.end());
        
        // std::cout << "maxL: ";
        // for (auto& i : maxL)
        // {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;
        
        // std::cout << "maxR: ";
        // for (auto& i : maxR)
        // {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;

        int res = 0;
        for (int i = 1; i < height.size() - 1; ++i)
        {
            int curr = std::min(maxL[i-1], maxR[i-1]) - height[i];

            if (curr > 0)
                res += curr;
        }

        return res;
    }
};
