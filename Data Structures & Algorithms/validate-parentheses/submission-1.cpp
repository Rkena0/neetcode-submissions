class Solution {
public:
    bool isValid(string s) 
    {
        std::vector<char> stack;
        std::map<char,char> closeOpen = {{')','('}, {'}','{'}, {']','['}};
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push_back(s[i]);
            else 
                if (!stack.empty() && stack.back() == closeOpen[s[i]])
                {
                    stack.pop_back();
                }
                else
                    return false;
        }

        if (stack.empty())
            return true;
        
        return false;       
    }
};
