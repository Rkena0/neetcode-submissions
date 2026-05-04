class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int res = 0;

        std::unordered_map<char, int> letters;
        int l = 0;
        int r = 0;
        int maxF = 1;
        ++letters[s[r]];
        while (r < s.size())
        {
            int length = r-l + 1;
            // std::cout << "r, l: " << r << "," << l << std::endl;
            // std::cout << "length-maxF: " << length-maxF << std::endl;
            
            if (length-maxF <= k)
            {
                res = std::max(res, length);
                
                ++r;
                ++letters[s[r]];

                if (letters[s[r]] > maxF)
                {
                    maxF = letters[s[r]];
                }
            }
            else
            {
                --letters[s[l]];
                ++l;
            }
        }
        return res;
    }
};