class LRUCache {
private:
    unordered_map<int, pair<int,int>> cache;
    int capacity;
    int timestamp;
public:
    LRUCache(int capacity) : capacity(capacity), timestamp(0) {}
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        cache[key].second = timestamp++;
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            cache[key] = {value,timestamp++};
        else 
        {
            if(cache.size()>=capacity)
            {
                int minTime = INT_MAX;
                int keyToRemove = -1;
                for(const auto& pair:cache)
                {
                    if(pair.second.second < minTime)
                    {
                            minTime = pair.second.second;
                            keyToRemove = pair.first;
                    }
                }
                cache.erase(keyToRemove);
            }
            cache[key] = {value, timestamp++};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
