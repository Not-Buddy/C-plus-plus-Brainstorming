#include <bits/stdc++.h>
using namespace std;

int FirstWrongDecision(string s) {
    size_t pos = s.find('W');
    if (pos == string::npos)
        return -1;
    else
        return static_cast<int>(pos);
}


int main() {
    string str;
    cin >> str;
    // Call the function FirstWrongDecision().
    cout << FirstWrongDecision(str) << endl;
    return 0;
}
