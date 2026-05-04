class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        //nlogm
        int max = 0;
        for (auto i : piles)
            max = std::max(max, i);

        int l = 1;
        int r = max;

        int res = INT_MAX;
        while (l <= r)
        {
            int k = (r+l)/2;

            int currH = 0;
            for (int i = 0; i < piles.size(); ++i)
            {
                int currB = piles[i]/k;
                if (piles[i]%k)
                    ++currB;

                currH += currB;
            }

            if (currH <= h)
            {
                res = std::min(res, k);

                r = k - 1;
            }
            else if (currH > h)
            {
                l = k + 1;
            }
        }

        return res;
    }
};
