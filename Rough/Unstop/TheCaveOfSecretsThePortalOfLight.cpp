#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> computeXY(const string& s, const string& target) {
    int X = 0, Y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 's' && target[i] == 'l') X++;
        else if (s[i] == 'l' && target[i] == 's') Y++;
    }
    return {X, Y};
}

int computeOperations(int X, int Y, int delta_l) {
    if (delta_l > 0) {
        int changes_fix = min(delta_l, X);
        X -= changes_fix;
        int changes_remaining = delta_l - changes_fix;
        Y += changes_remaining;
    } else if (delta_l < 0) {
        int changes_fix = min(-delta_l, Y);
        Y -= changes_fix;
        int changes_remaining = -delta_l - changes_fix;
        X += changes_remaining;
    }
    return abs(delta_l) + X; // X should equal Y here
}

int main() {
    int N;
    string S;
    cin >> N >> S;

    int min_ops = INT_MAX;

    for (int start = 0; start < 2; ++start) {
        char current_char = (start == 0) ? 'l' : 's';
        string target;
        for (int i = 0; i < N; ++i) {
            target += current_char;
            current_char = (current_char == 'l') ? 's' : 'l';
        }

        auto [X, Y] = computeXY(S, target);
        int l_req = count(target.begin(), target.end(), 'l');
        int l_current = count(S.begin(), S.end(), 'l');
        int delta_l = l_req - l_current;

        int ops = computeOperations(X, Y, delta_l);
        if (ops < min_ops) {
            min_ops = ops;
        }
    }

    cout << min_ops << endl;

    return 0;
}
