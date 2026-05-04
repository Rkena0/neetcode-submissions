class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        std::vector<int> letters(26);
        for (auto ch : s)
        {
            ++letters[ch - 'a'];
        }

        for (auto ch : t)
        {
            int currCh = ch - 'a';
            --letters[currCh];
        }

        for (int i : letters)
        {
            if (i != 0)
                return false;
        }
        
        return true;

    }
};
