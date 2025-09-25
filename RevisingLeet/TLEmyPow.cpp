class Solution {
public:
    double myPow(double x, int n) {
        double result{1};
        if(n==0)
            return 1;

        if(n<0)
        {
            for(int i{n};i<0;i++)
            {
                result = result / x;
            }
            return result;
        }

        for(int i{};i<n;i++)
        {
            result = result * x;
        }
        return result;
    }
};