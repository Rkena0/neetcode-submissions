class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (data_.count(key) == 0)
            return -1;

        // update timestamp
        auto& it = data_[key];
        recentUsedKeyValue_.splice(recentUsedKeyValue_.end(), recentUsedKeyValue_, it);

        return it->second;
    }
    
    void put(int key, int value) {

        // del key if size > capacity
        if (data_.count(key) == 0)
        {
            recentUsedKeyValue_.push_back({key, value});
            data_[key] = --recentUsedKeyValue_.end();
        }
        else
        {
            auto& it = data_[key];
            recentUsedKeyValue_.splice(recentUsedKeyValue_.end(), recentUsedKeyValue_, it);
            it->second = value;            
        }

        if (recentUsedKeyValue_.size() > capacity_)
        {
            auto it = recentUsedKeyValue_.begin();
            // del coresponding item in data_
            data_.erase(it->first);
            recentUsedKeyValue_.erase(it);
        }     
    }
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> data_;
    std::list<std::pair<int, int>> recentUsedKeyValue_;
    int capacity_ = 1; 
};
