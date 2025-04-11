#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Solve(int n, int k, string input)
{
    // Edge case: single character
    if (n == 1) return false;
    
    // Case 1: Original string is already smaller than its reversed version
    string reversed_str = input;
    reverse(reversed_str.begin(), reversed_str.end());
    if (input < reversed_str) return true;
    

    //Two cases where one could be palindrome and other could be normal string
    if(k>=1)
    {
        char max_char = *max_element(input.begin(), input.end());
        char min_char = *min_element(input.begin(), input.end());
        if(reversed_str!=input)
        { 
            if(min_char!=max_char)
            {
                return true;
            }
        }
        else 
        {
            if(min_char!=max_char)
            {
                return true;
            }
        }
    } 
    return false;
}


int main() 
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    
    for (int i = 0; i < testcases; i++) 
    {
        int n, k;
        string input;
        cin >> n >> k;
        cin.ignore();
        getline(cin, input);
        bool result = Solve(n, k, input);
        cout << (result ? "YES" : "NO") << '\n';
    }
    return 0;
}
