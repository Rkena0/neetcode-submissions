class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
        : k_(k), heap_(nums.begin(), nums.end())
    {
        while (heap_.size() > k)
            heap_.pop();

    }
    
    int add(int val) {
        heap_.push(val);
        if (heap_.size() > k_)
            heap_.pop();

        return heap_.top();
    }

private:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap_;
};
