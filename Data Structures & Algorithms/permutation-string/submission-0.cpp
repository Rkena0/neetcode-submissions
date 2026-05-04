class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        std::unordered_map<char, int> let1, let2;

        for (int i = 0; i < s1.size(); ++i)
        {
            ++let1[s1[i]];
        }

        int l = 0;
        int r = 0;
        while (r < s2.size())
        {
            if (let1[s2[r]] > 0)
            {
                --let1[s2[r]];
                ++r;

                if (r-l == s1.size())
                    return true;
            }
            else if (l < r)
            {
                ++let1[s2[l]];
                ++l;
            }
            else
            {
                ++l;
                ++r;
            }
        }

        return false;        
    }
};
