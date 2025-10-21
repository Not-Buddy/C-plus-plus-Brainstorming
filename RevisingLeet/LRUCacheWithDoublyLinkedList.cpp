class LRUCache 
{
private:
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    
public:
    LRUCache(int capacity) 
    {
     cap = capacity;   
    }
    
    int get(int key) 
    {
        if(mp.find(key) == mp.end()) return -1;
        dq.splice(dq.begin(),dq,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            dq.splice(dq.begin(), dq, mp[key]);
            mp[key] -> second = value;
            return;            
        }
        if(dq.size()==cap)
        {
            int lastKey = dq.back().first;
            dq.pop_back();
            mp.erase(lastKey);
        }
        dq.push_front({key,value});
        mp[key] = dq.begin();
    }
};
