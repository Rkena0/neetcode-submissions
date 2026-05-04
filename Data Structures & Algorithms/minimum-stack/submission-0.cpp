class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data_.push_back(val);
        
        if (minimums_.empty() || minimums_.back().first > val)
            minimums_.push_back({val, data_.size() - 1});

    }
    
    void pop() {
        if (minimums_.back().first == data_.back() && minimums_.back().second == data_.size() - 1)
            minimums_.pop_back();

        data_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        return minimums_.back().first;
    }
private:
    std::vector<int> data_;
    std::vector<std::pair<int, int>> minimums_;
    int min;
};
