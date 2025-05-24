#include <iostream>
#include <vector>
using namespace std;
vector<bool> sieveOfEratosthenes(int n) {
    // Create a boolean array "isPrime" and initialize all entries as true.
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    // Start from 2 and mark all multiples of each prime as not prime
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

int count_brave_soldiers(int n) 
{
    vector<bool> isPrime=sieveOfEratosthenes(n);
    int Brave{};
    for(auto i:isPrime)
    {
        if(i)
            Brave++;
    }
    // Write your logic here.
    return Brave;
}

int main() {
    int n;
    std::cin >> n;
    int result = count_brave_soldiers(n);
    std::cout << result << std::endl;
    return 0;
}
