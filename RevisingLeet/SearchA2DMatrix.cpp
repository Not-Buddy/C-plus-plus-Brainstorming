class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::unordered_map<int,int> hash{};
        for(auto vec:matrix)
        {
            for(auto i:vec)
                hash[i]++;
        }
        if(hash.find(target)!=hash.end())
            return true;
        else
            return false;
    }
};
