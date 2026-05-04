class Solution {
public:
    bool isNumber(const std::string& str, int& num)
    {
        if (str.empty())
            return false;

        bool isNeg = str[0] == '-' ? true : false;
        int indx = isNeg? 1 : 0;
        
        if (isNeg && str.size() == 1)
            return false;
        
        int tempNum = 0;
        while (indx < str.size())
        {
            if (!std::isdigit(str[indx]))
                return false;
            
            tempNum *= 10;
            tempNum += str[indx] - '0';

            ++indx;
        }

        num = isNeg ? tempNum * -1: tempNum;

        return true;
    }

    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> st;

        for (int i = 0; i < tokens.size(); ++i)
        {
            int currNumber = 0;
            std::string curr = tokens[i];
            if (isNumber(curr, currNumber))
            {
                st.push(currNumber);
                //std::cout << currNumber << std::endl;
            }
            else
            {
                int rNum = st.top();
                st.pop();
                int lNum = st.top();
                st.pop();

                int res;
                if (curr == "+")
                {
                    res = lNum + rNum;
                }
                else if (curr == "-")
                {
                    res = lNum - rNum;
                }
                else if (curr == "*")
                {
                    res = lNum * rNum;
                }
                else if (curr == "/") 
                {
                    res = lNum / rNum;
                }

                st.push(res);
                //std::cout << "res: "<< res << std::endl;
            }
        }

        return st.top();
    }
};
