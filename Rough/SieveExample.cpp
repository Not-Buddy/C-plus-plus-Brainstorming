#include <iostream>
#include <vector>
using namespace std;

// Function to perform the Sieve of Eratosthenes
vector<int> sieveOfEratosthenes(int N) {
    // Create a boolean vector and initialize all entries as true.
    // isPrime[i] will be true if i is a prime number.
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    // Start marking multiples of each prime number
    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Collect all prime numbers into a vector
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<int> primes = sieveOfEratosthenes(N);

    cout << "Prime numbers up to " << N << " are:" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

