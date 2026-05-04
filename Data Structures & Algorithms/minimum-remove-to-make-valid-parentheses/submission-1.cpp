class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        std::queue<std::pair<char,int>> st;
        std::set<int> toDel;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push({'(', i});
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                    toDel.insert(i);
                else
                {
                    st.pop();
                }
            }
        }

        while (!st.empty())
        {
            toDel.insert(st.front().second);
            st.pop();
        } 


        std::string res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (toDel.find(i) == toDel.end())
                res.push_back(s[i]);
        }


        return res;
    }
};
