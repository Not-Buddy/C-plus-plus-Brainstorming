class Solution {
public:
    double myPow(double x, int n) {
        // Cast n to long long to handle the INT_MIN overflow edge case.
        // If n = -2147483648, then -n would be 2147483648, which overflows a 32-bit int.
        long long N = n;

        // Handle negative exponents by inverting x and making the exponent positive.
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        // This loop implements binary exponentiation.
        while (N > 0) {
            // If N is odd, the current power of x is needed.
            // (This corresponds to a '1' in the binary representation of the original n).
            if (N % 2 == 1) {
                result = result * x;
            }

            // Square x to prepare for the next bit of the exponent.
            // The value of x progresses as x^1, x^2, x^4, x^8, etc.
            x = x * x;

            // Halve N, effectively a right-shift in binary.
            N = N / 2;
        }

        return result;
    }
};