#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int nthPrime(int n) {
    int count = 0;
    int candidate = 1;
    while (count < n) {
        candidate++;
        if (isPrime(candidate)) {
            count++;
        }
    }
    return candidate;
}

int main() 
{
    int n{};
    cin >> n;
    if(n <= 0) {
        cout << "Invalid input";
        return 1;
    }
    int out = nthPrime(n);  
    cout << out * out; // Use integer multiplication instead of pow()
    return 0;
}

