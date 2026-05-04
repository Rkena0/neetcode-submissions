class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int maxVal = 0;
        char maxFreq;
        std::set<char> letters;
        for (int i = 0; i < s.size(); ++i)
        {
            letters.insert(s[i]);
        }

        int res = 0;
        int l = 0;
        int r = 0;  
        int currK = k;

        for (auto currLetter : letters)
        {
            l = 0;
            r = 0;  
            currK = k;

            while(r < s.size())
            {
                if (s[r] == currLetter)
                {
                    ++r;
                }
                else if (currK > 0)
                {
                    ++r;
                    --currK;
                    std::cout << currLetter << " " << l << " " << r << std::endl;
                }
                else
                {
                    res = std::max(res, r-l);
                    if (s[l] != currLetter)
                    {
                        //std::cout << currLetter << " " << l << std::endl;
                        ++currK;
                    }
                    
                    ++l;
                }
            }
            res = std::max(res, r-l);
        }

        return res;
    }
};