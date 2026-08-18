class Solution {
public:
    string reorganizeString(string s) {
        std::unordered_map<char, int> freq_map{};
        std::priority_queue<pair<int,char>> pq{};

        for(const auto c:s)
            freq_map[c]++;

        for(const auto &f:freq_map)
            pq.push({f.second,f.first});

        std::string res = "";
        std::pair<int, char> prev = {0, '#'};

        while(!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            res += current.second;
            current.first--;

            if(prev.first>0){
                pq.push(prev);
            }
            prev = current;
        }
        
        if(res.size() != s.size())
            return "";

    return res;
    }
};
