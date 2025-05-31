#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int F = count(str.begin(), str.end(), 'F');
    int B = count(str.begin(), str.end(), 'B');
    int L = count(str.begin(), str.end(), 'L');
    int R = count(str.begin(), str.end(), 'R');

    // The minimum number of moves needed to reach the destination:
    // |F - B| (net vertical) + |L - R| (net horizontal)
    int min_moves = abs(F - B) + abs(L - R);

    // The rest can be deleted
    int deletable = str.size() - min_moves;
    cout << deletable << endl;
    return 0;
}

