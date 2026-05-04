class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        data_[key][timestamp] = value;    
    }
    
    string get(string key, int timestamp) 
    {
        if (data_.count(key) == 0)
        {
            return "";
        }

        auto& t2Value = data_[key];

        auto it = t2Value.lower_bound(timestamp);

        if (it != t2Value.end() && it->first == timestamp)
            return it->second;
        
        if (it == t2Value.begin())
            return "";

        --it;
        return it->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> data_;    
};
