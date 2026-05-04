class Solution {
public:
    string minWindow(string s, string t) 
    {
        std::unordered_map<char, int> letT;
        for (auto ch : t)
            ++letT[ch];
        
        int l = 0;
        int r = 0;
        
        int res = INT_MAX;
        int resL = 0;
        int resR = 0;

        int need = letT.size();
        int matches = 0;

        while (r < s.size())
        {
            if (letT.count(s[r]) > 0)
            {
                --letT[s[r]];
                if (letT[s[r]] == 0)
                    ++matches;
                
                while (matches == need)
                {
                    int candRes = r-l+1;
                    if (candRes < res)
                    {
                        res = candRes;
                        resL = l;
                        resR = r;
                    }

                    //std::cout << "l: " << l << ", s[l]: " << s[l] << std::endl;
                    //std::cout << "r: " << r << ", s[r]: " << s[r] << std::endl;
                    ++letT[s[l]];
                    if (letT[s[l]] > 0)
                        --matches;

                    if (l == r)
                    {
                        ++l;
                        ++r;
                        continue;
                    }   

                    ++l;
                    while (letT.count(s[l]) == 0 && l < r)
                    {
                        //std::cout << "next L: ";
                        //std::cout << "l: " << l << ", s[l]: " << s[l] << std::endl;
                        ++l;   
                    }
                }
                
                ++r;
            }
            else if (l == r)
            {
                ++l;
                ++r;
            }
            else 
            {
                ++r;
            }
        }

        if (res == INT_MAX)
            return "";
        std::cout << "resL: " << resL << ", resR: " << resR << std::endl;
        return s.substr(resL, resR-resL+1);
    }
};
