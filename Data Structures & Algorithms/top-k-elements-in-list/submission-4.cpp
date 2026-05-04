class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        std::vector<int> el2count(2001);
        for (int i = 0; i < nums.size(); ++i)
        {
            int currEl = nums[i]+1000;
            ++el2count[currEl];
        }

        std::vector<std::vector<int>> counts(10000+1, std::vector<int>());
        for (int i = 0; i < el2count.size(); ++i)
        {
            int currCount = el2count[i];
            int currNum = i-1000;
            
            if (currCount > 0)
                counts[currCount].push_back(currNum);
        }

        std::vector<int> res;
        for (int i = 10000; i > 0; --i)
        {
            if (k <= 0)
                break;

            if (counts[i].size() > 0)
            {
                for (auto& el : counts[i])
                {
                    if (k <= 0)
                        break;
                    
                    k--;
                    res.push_back(el);
                }
            }
        }

        return res;
    }
};
