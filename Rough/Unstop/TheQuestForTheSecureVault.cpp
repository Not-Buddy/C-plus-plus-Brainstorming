#include <iostream>
using namespace std;

#include <vector>
#define MOD 1000000007

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int count_valid_pins(int N) {
    // Sieve to count primes up to N (1-based)
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    int cnt_prime = 0;
    for (int i = 1; i <= N; ++i)
        if (is_prime[i]) cnt_prime++;
    int cnt_nonprime = N - cnt_prime;

    long long ans = (mod_pow(4, cnt_prime, MOD) * mod_pow(5, cnt_nonprime, MOD)) % MOD;
    return static_cast<int>(ans);
}


int main() {
    int N;
    cin >> N; // Read the integer N
    // Call user logic function and print the output
    int result = count_valid_pins(N);
    cout << result << endl;
    return 0;
}
