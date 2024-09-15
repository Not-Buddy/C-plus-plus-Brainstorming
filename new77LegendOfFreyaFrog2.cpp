
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int testcases{};
	cin>>testcases;
	cin.ignore();
	for(int i{0};i<testcases;i++)
	{
    		int x, y, k;
    
    		cin >> x >> y >> k;

    // Calculating the result using the given formula
    int result = max(2 * ((x + k - 1) / k) - 1, 2 * ((y + k - 1) / k));

    // Output the result
    cout << result << endl;
	}

    return 0;
}

