class Solution 
{
    public:
        bool IsDigit(char &ch)
        {
            printf("char %c\n",ch);
            if(ch>='0' && ch<='9')
                return true;
            return false;
        }
        int myAtoi(string s)
        {
            if(s.empty())
                return 0;
            
                const long long MAX_INT=INT_MAX;
                const long long MIN_INT=INT_MIN;

                long long ret = 0;
                int sign = 1;
                for(int i{};i<s.size();i++)
                {
                    if(i==0 && s[i]==' ')
                        continue;
                    else if(s[i] == ' ' && ( i > 0 && s[i-1] != ' '))
                        break;
                    else if(s[i]==' ')
                        continue;

                    if(s[i] == '-' || s[i] == '+')
                    {
                        if(i == s.size()-1)
                            continue;
                        if(s[i]=='-')
                            sign=-1;
                        if(i==0||(i>0&&s[i-1]==' '))
                            continue;
                    }

                    if(!isdigit(s[i]))
                    {
                        if(s[i]=='-') 
                            sign=1;
                        
                            
                        break;
                    }

                    auto num = s[i] - '0';
                    ret = ret*10+num;

                    if((ret* sign)<= INT_MIN)
                        return INT_MIN;
                    if((ret * sign )>= INT_MAX)
                        return INT_MAX;
                }
                return static_cast<int>(ret*sign);
        }
};