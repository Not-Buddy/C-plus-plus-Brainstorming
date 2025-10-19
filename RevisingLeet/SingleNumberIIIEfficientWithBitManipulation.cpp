class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int Xor{},mask{1},first{};
        for(auto i:nums)
            Xor^=i;
        while(!(mask&Xor))
            mask<<=1;
        for(auto i:nums)
            if(i & mask)
                first^=i;
        return {first,Xor^first};
    }
};
