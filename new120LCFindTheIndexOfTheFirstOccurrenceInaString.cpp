class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int n= haystack.size();
        int needle_size= needle.size();
        for(int i{0};i<=n-needle_size;i++)
        {
            if(haystack.substr(i,needle_size)==needle)
            {
                return i;
            }
        }
        return -1;
    }
};
