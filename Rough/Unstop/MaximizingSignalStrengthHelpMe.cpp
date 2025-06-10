#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double maximize_average_efficiency(int n, vector<int>& efficiencies) {
    if (n < 5) {
        return 0.00000;
    }
    
    int num_remove = n / 5;  // Number of components to remove
    sort(efficiencies.begin(), efficiencies.end());  // Sort in ascending order
    
    // Remove the lowest 'num_remove' components by using iterators
    vector<int> remaining_efficiencies(efficiencies.begin() + num_remove, efficiencies.end());
    
    // Calculate the average efficiency of remaining components
    double sum_efficiency = 0;
    for (int val : remaining_efficiencies) {
        sum_efficiency += val;
    }
    
    double avg_efficiency = sum_efficiency / remaining_efficiencies.size();
    return avg_efficiency;
}

int main() {
    int n;
    cin >> n;
    vector<int> efficiencies(n);
    for (int i = 0; i < n; i++) {
        cin >> efficiencies[i];
    }
    
    double result = maximize_average_efficiency(n, efficiencies);
    cout << fixed << setprecision(5) << result << endl;
    return 0;
}
