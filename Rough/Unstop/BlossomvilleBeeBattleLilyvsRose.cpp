#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> user_logic(int n1, const vector<int>& flowers, int n2, const vector<int>& herbs) {
    // Count occurrences of flowers and herbs
    unordered_map<int, int> flower_count;
    unordered_map<int, int> herb_count;
    
    for (int flower : flowers) {
        flower_count[flower]++;
    }
    
    for (int herb : herbs) {
        herb_count[herb]++;
    }
    
    // Filter flowers where Lily has strictly more than Rose
    vector<int> result;
    for (int flower : flowers) {
        if (flower_count[flower] > herb_count[flower]) { // herb_count[flower] defaults to 0
            result.push_back(flower);
        }
    }
    
    return result.empty() ? vector<int>{-1} : result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n1;
    cin >> n1;
    vector<int> flowers(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> flowers[i];
    }
    
    int n2;
    cin >> n2;
    vector<int> herbs(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> herbs[i];
    }
    
    vector<int> result = user_logic(n1, flowers, n2, herbs);
    
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}
