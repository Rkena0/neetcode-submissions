class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) 
    {
            std::vector<std::pair<int, int>> vec;
            for (int i = 0; i < p.size(); ++i)
            {
                vec.push_back(std::make_pair(p[i],s[i]));
            }

            std::sort(vec.begin(), vec.end());

            std::vector<double> vecT(vec.size());
            for (int i = 0; i < vec.size(); ++i)
            {
                double currT = (target - vec[i].first)/double(vec[i].second);
                
                vecT[i] = currT;
            }

            std::stack<double> st;
            st.push(vecT[0]);
            for (int i = 1; i < vecT.size(); ++i)
            {
                double currT = vecT[i];
                while (!st.empty() && currT >= st.top())
                {
                    st.pop();
                }

                st.push(currT);
            }

            return st.size();
    }
};
