class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> h;

        for (auto& i : nums)
        {
            h.push(i);
            if (h.size() > k)
                h.pop();
        }

        return h.top();
    }
};
