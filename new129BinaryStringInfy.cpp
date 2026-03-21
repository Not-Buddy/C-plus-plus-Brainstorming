#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int getMaximumBinaryValue(int N, vector<long long>& A, vector<long long>& B) {
    // 1. Sort A descending (Biggest blocks of 1s first)
    sort(A.begin(), A.end(), greater<long long>());
    
    // 2. Sort B ascending (Smallest blocks of 0s first)
    sort(B.begin(), B.end());
    
    long long ans = 0;
    
    for (int i = 0; i < N; ++i) {
        // --- Process the block of 1s ---
        // CRITICAL: A[i] MUST be <= 62 for this shift to not overflow a 64-bit integer
        long long shift_A = (1LL << A[i]) % MOD; 
        
        // The decimal value of a block of A[i] ones is (2^A[i] - 1)
        long long ones_val = (shift_A - 1 + MOD) % MOD; 
        
        // Shift the current answer left by A[i] bits, then add the new 1s
        ans = (ans * shift_A) % MOD;       
        ans = (ans + ones_val) % MOD;  
        
        // --- Process the block of 0s ---
        // CRITICAL: B[i] MUST be <= 62 for this shift to not overflow
        long long shift_B = (1LL << B[i]) % MOD;
        
        // Shift the current answer left by B[i] bits (adding 0s doesn't add value)
        ans = (ans * shift_B) % MOD;       
    }
    
    return ans;
}

int main() {
    // Example test case: N = 2, A = [1, 2], B = [1, 1]
    // Arranges to: 2 ones, 1 zero, 1 one, 1 zero -> "11010" -> Decimal 26
    int N = 2;
    vector<long long> A = {1, 2};
    vector<long long> B = {1, 1};
    
    cout << "Maximum value modulo 10^9+7 is: " << getMaximumBinaryValue(N, A, B) << endl;
    
    return 0;
}
