class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
        std::vector<int> res(t.size());
        std::stack<std::pair<int,int>> st;

        for (int i = 0; i < t.size(); ++i)
        {
            while (!st.empty() && t[i] > st.top().first)
            {
                int currI = st.top().second;
                st.pop();

                res[currI] = i-currI;
            }

            st.push({t[i], i});
        }

        while (!st.empty())
        {
            int currI = st.top().second;
            st.pop();

            res[currI] = 0;
        }

        return res;
    }
};
