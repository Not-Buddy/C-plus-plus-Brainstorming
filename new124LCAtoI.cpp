class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
  
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
        
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && result > (long long)INT_MAX + 1) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return (int)(sign * result);
    }
};

