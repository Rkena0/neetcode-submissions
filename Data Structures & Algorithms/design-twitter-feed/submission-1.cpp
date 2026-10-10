class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postsPerUserTimestamp2Post_[userId].push_front(std::make_pair(time_++, tweetId));


    }
    
    vector<int> getNewsFeed(int userId) {
        using ListIter = std::list<std::pair<int, int>>::iterator;
        auto pred = [](auto& lha, auto& rha)
        {
            return lha.first->first < rha.first->first;
        };
        std::priority_queue<std::pair<ListIter, ListIter>, std::vector<std::pair<ListIter, ListIter>>, decltype(pred)> heap; 

        if (!postsPerUserTimestamp2Post_[userId].empty())
            heap.push(std::make_pair(postsPerUserTimestamp2Post_[userId].begin(), postsPerUserTimestamp2Post_[userId].end()));

        auto& followeeIds = folowersUser2User_[userId];
        for (auto usrIdIt = followeeIds.begin(); usrIdIt != followeeIds.end(); ++usrIdIt)
        {
            if (!postsPerUserTimestamp2Post_[*usrIdIt].empty())
                heap.push(std::make_pair(postsPerUserTimestamp2Post_[*usrIdIt].begin(), postsPerUserTimestamp2Post_[*usrIdIt].end()));
        }

        std::vector<int> res;

        std::cout << "heap: " << heap.size() << std::endl;
        while (!heap.empty() && res.size() < 10)
        {
            std::pair<ListIter, ListIter> currPost = heap.top();
            heap.pop();
            res.push_back(currPost.first->second);
          
            ++currPost.first;
            if (currPost.first != currPost.second)
                heap.push(currPost);            
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        folowersUser2User_[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        folowersUser2User_[followerId].erase(followeeId);
    }

private:
    // add by user key, remove from users cont O(1)
    std::unordered_map<int, std::unordered_set<int>> folowersUser2User_;
    std::unordered_map<int, std::list<std::pair<int, int>>> postsPerUserTimestamp2Post_;

    int time_ = 0; 
};
