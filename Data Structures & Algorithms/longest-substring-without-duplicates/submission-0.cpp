class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // unordered_map to check current substr contains symbol
        // sliding window while no duplicate
        // if duplicate erase leftmost element
        int maxVal = 0;

        std::unordered_set<char> sub{};
        int l = 0;
        int r = 0;
        while (r < s.size())
        {
            if (sub.count(s[r]) > 0)
            {
                maxVal = std::max(int(sub.size()), maxVal);
                sub.erase(s[l++]);
            }
            else
            {
                sub.insert(s[r++]);
            }
        }

        if (sub.size())
            maxVal = std::max(int(sub.size()), maxVal);

        return maxVal;
    }
};
