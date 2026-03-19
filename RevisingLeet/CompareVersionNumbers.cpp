class Solution {
public:
    int compareVersion(string v1, string v2) {

        int i{};
        int j{};
        
        int maxlen = max(v1.size(),v2.size());

        for(int k{0};k<maxlen;k++)
        {
            int num1{}, num2{};

            string s1{},s2{};

            while(i<v1.size() && v1[i]!='.')
            {
                s1+=v1[i];
                i++;
            }

            if(s1.size()>0) num1 = stoi(s1);

            while(j<v2.size() && v2[j]!='.')
            {
                s2+=v2[j];
                j++;
            }
            if(s2.size()>0) num2 = stoi(s2);

            if(num1>num2) return 1;
            else if (num1<num2) return -1;
            i++;
            j++;
        }

        return 0;
    }
};
