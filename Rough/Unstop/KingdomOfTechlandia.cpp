#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

void validate_password(const vector<int>& password, string& result, int& most_frequent_element)
{
    unordered_map<int, int> freqMap;
    for (int val : password)
        freqMap[val]++;

    // Check if all elements appear an even number of times
    bool all_even = true;
    bool at_least_one_twice = false;
    int maxFreq = 0;
    most_frequent_element = 0;

    for (const auto& kv : freqMap)
    {
        if (kv.second % 2 != 0)
            all_even = false;
        if (kv.second == 2)
            at_least_one_twice = true;
        if (kv.second > maxFreq || (kv.second == maxFreq && kv.first < most_frequent_element))
        {
            maxFreq = kv.second;
            most_frequent_element = kv.first;
        }
    }

    if (all_even && at_least_one_twice)
        result = "VALID";
    else
        result = "INVALID";
}

int main()
{
    int N;
    cin >> N;
    vector<int> password(N);
    for (int i = 0; i < N; ++i)
        cin >> password[i];

    string validation_result;
    int most_frequent_element;
    validate_password(password, validation_result, most_frequent_element);
    cout << validation_result << '\n';
    cout << most_frequent_element << '\n';
    return 0;
}

