class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> num2count;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++num2count[nums[i]];
        }

        std::priority_queue<std::pair<int,int>> maxHeap;
        for (auto& pr : num2count)
        {
            auto count2num = std::make_pair(pr.second, pr.first);
            maxHeap.push(count2num);
        }

        vector<int> res;
        while(k--)
        {
            int curr = maxHeap.top().second;
            maxHeap.pop();

            res.push_back(curr);
        }
        
        return res;
     
    }
};
