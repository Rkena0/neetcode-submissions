class Solution {
public:

    string encode(vector<string>& strs) 
    {
        std::string encoded;
        
        for (int i = 0; i < strs.size(); ++i)
        {
            auto& currStr = strs[i];
            encoded += std::to_string(currStr.size());
            //std::cout << "encode: " << currStr.size() << std::endl;
            
            encoded += '#';
            encoded += currStr;
        }

        return encoded;
    }

    vector<string> decode(string s) 
    {
        //std::cout << s << std::endl;
        std::vector<std::string> decodedStrs;

        char delim;
        int i = 0;
        while (i < s.size())
        {
            size_t currStrSize = 0;
            while (s[i] != '#')
            {
                currStrSize *= 10;
                currStrSize += s[i] - '0';

                ++i;
            }
            //std::cout << currStrSize << std::endl;
            
            delim = s[i++];
            if (delim != '#')
                std::cout << "wtf" << std::endl;

            std::string currStr;
            for (int j = 0; j < currStrSize; ++j)
            {
                char currCh = s[i];
                currStr.push_back(currCh);

                ++i;
            }

            decodedStrs.push_back(currStr);
        }
        
                
        return decodedStrs;
    }
};
