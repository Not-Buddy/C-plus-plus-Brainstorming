class LFUCache {
private:
    unordered_map<int, tuple<int,int,int>> cache;
    // key -> 0 value, 1 frequency, 2 timestamp
    int capacity;
    int timestamp;

public:
    LFUCache(int capacity) : capacity(capacity), timestamp(0) {}
    
    int get(int key) 
    {
        if(cache.find(key) == cache.end())
            return -1;

        get<1>(cache[key])++;
        get<2>(cache[key]) = timestamp++;
        return get<0>(cache[key]);    
    }
    
    void put(int key, int value) 
    {
        if(capacity <= 0) return;

        if(cache.find(key) != cache.end())
        {
            get<0>(cache[key]) = value;
            get<1>(cache[key])++;
            get<2>(cache[key]) = timestamp++;
            return;
        }
        if(cache.size()>=capacity)
        {
            int minFreq = INT_MAX;
            int minTime = INT_MAX;
            int keyToRemove = -1;
            
            for(const auto& pair : cache)
            {
                int freq = get<1>(pair.second);
                int time = get<2>(pair.second);

                if(freq<minFreq || (freq== minFreq && time < minTime))
                {
                    minFreq = freq;
                    minTime = time;
                    keyToRemove = pair.first;
                }
            }
            cache.erase(keyToRemove);
        }    
        cache[key] = make_tuple(value, 1, timestamp++);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
