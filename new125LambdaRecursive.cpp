#include <iostream>
using namespace std;

int main() {
    int x = 5;
    auto recur = [](int a, auto& self) -> void {
        if(a == 1)
            return;
        cout << a << "\n";
        self(a - 1, self);
    };

    recur(x, recur);
    return 0;
}

