class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int result = 0;

        if (prices.size() == 0)
            return result;
        int currMin = prices[0];
        for (int i = 0; i < prices.size(); ++i)
        {
            if (currMin < prices[i])
                result = std::max(result, prices[i] - currMin);
            else
                currMin = prices[i];
        }
        
        return result;
    }
};
