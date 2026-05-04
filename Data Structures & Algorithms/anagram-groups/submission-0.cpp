class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::string,std::vector<std::string>> anagram2bucket;

        for (int i = 0; i < strs.size(); ++i)
        {
            std::string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());

            anagram2bucket[sorted].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> res;
        for (auto pr : anagram2bucket)
        {
            res.push_back(pr.second);
        }

        return res;
    }
};
