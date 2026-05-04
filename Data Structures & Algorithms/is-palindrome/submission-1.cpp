class Solution {
public:
    bool isPalindrome(string s) 
    {
        s.erase(std::remove_if(s.begin(),s.end()
                , [](char c){ return !(isalpha(c) || isdigit(c)) || (c == ' ');}
                )
                ,s.end());
        std::cout << s << std::endl;

        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c){ return std::tolower(c); });
        
        std::cout << s << std::endl;

        for (int i = 0; i < s.size()/2; ++i)
        {
            if (s[i] != s[s.size()-1-i])
                return false;
        }  

        return true; 
    }
};
