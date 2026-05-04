class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        // index: heights >= before it 
        std::stack<std::pair<int, int>> st;
        st.push({0, 1});

        std::vector<int> wd(h.size());
        int r = 1;
        while (r < h.size())
        {
            auto topSt = st.top();
            //std::cout << "topSt: " << topSt.first << ": " << topSt.second << std::endl;
            //std::cout << "h[r]: " << h[r] << std::endl;

            if (h[r] > h[topSt.first])
            {
                st.push({r, 1});
            }
            else if (h[r] == h[topSt.first])
            {
                ++st.top().second;
            }
            
            if (h[r] < h[topSt.first])
            {
                int curr = 0;
                while (!st.empty() && h[r] < h[topSt.first])
                {
                    wd[topSt.first] = topSt.second + curr;
                    curr += topSt.second;
                    std::cout << "h[r]: " << h[r] << std::endl;
                    std::cout << "topStFinal: " << h[topSt.first] << ": " << topSt.second << std::endl;

                    st.pop();
                    if (!st.empty())
                    {
                        topSt = st.top();
                        std::cout << "after pop: " << h[topSt.first] << ": " << topSt.second << std::endl;
                    }
                }

                st.push({r, curr + 1});
            }
            
            ++r;
        }

        std::pair<int, int> topSt;
        int curr = 0;
        while (!st.empty())
        {
            topSt = st.top();
            curr = topSt.second;
            wd[topSt.first] = topSt.second;
            std::cout << "topStFinal: " << h[topSt.first] << ": " << topSt.second << std::endl;

            st.pop();
            if (!st.empty())
            {
                st.top().second += curr;
            }
        }

        int res = 0;
        for (int i = 0; i < wd.size(); ++i)
        {
            res = std::max(wd[i] * h[i], res);
        }

        return res;
    }
}; 
