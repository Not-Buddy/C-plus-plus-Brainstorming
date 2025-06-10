#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;

std::string user_logic(int n) {
    if (n == 0) {
        return "1";
    }

    std::vector<long long> dp(5, 1);

    for (int len = 2; len <= n; ++len) {
        std::vector<long long> next(5, 0);
        next[0] = (dp[1] + dp[4]) % MOD;
        next[1] = (dp[2] + dp[0]) % MOD;
        next[2] = (dp[3] + dp[1]) % MOD;
        next[3] = (dp[4] + dp[2]) % MOD;
        next[4] = (dp[0] + dp[3]) % MOD;
        dp = next;
    }

    long long result = 0;
    for (long long count : dp) {
        result = (result + count) % MOD;
    }

    std::string octal = "";
    while (result > 0) {
        octal = std::to_string(result % 8) + octal;
        result /= 8;
    }

    return octal.empty() ? "1" : octal;
}

int main() {
    int n;
    std::cin >> n;
    std::string result = user_logic(n);
    std::cout << result << std::endl;
    return 0;
}