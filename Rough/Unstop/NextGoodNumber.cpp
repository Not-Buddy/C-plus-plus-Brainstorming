#include <iostream>
#include <vector>
int next_good_number(int x) {
    auto is_good = [](int n) {
        while (n > 0) {
            if ((n % 10) % 2 == 0) return false;
            n /= 10;
        }
        return true;
    };
    int y = x + 1;
    while (!is_good(y)) ++y;
    return y;
}

int main() {
    int T;
    std::cin >> T;
    std::vector<int> results(T);

    for (int i = 0; i < T; ++i) {
        int x;
        std::cin >> x;
        results[i] = next_good_number(x);
    }

    for (const int &res : results) {
        std::cout << res << std::endl;
    }

    return 0;
}
