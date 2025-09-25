class Solution {
public:
    double myPow(double x, int n) {
        // Cast n to long long to handle the INT_MIN edge case
        long long N = n; 
        
        // Handle negative exponent
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return power(x, N);
    }
    
private:
    double power(double x, long long n) {
        // Base case: anything to the power of 0 is 1
        if (n == 0) {
            return 1.0;
        }
        
        // Recursively calculate half the power
        double half = power(x, n / 2);
        
        // Square the result of the half power
        double result = half * half;
        
        // If n is odd, we need one extra multiplication by x
        if (n % 2 == 1) {
            result = result * x;
        }
        
        return result;
    }
};