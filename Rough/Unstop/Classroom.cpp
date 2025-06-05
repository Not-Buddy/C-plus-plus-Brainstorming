#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> preferences(n + 1); // 1-indexed for students
    vector<bool> occupied(n + 1, false); // 1-indexed for seats
    vector<int> seating(n + 1); // seating[i] = seat number where student i sits
    
    for (int i = 1; i <= n; i++) {
        cin >> preferences[i];
    }
    
    // Process each student in order
    for (int student = 1; student <= n; student++) {
        int preferredSeat = preferences[student];
        int currentSeat = preferredSeat;
        
        // Search circularly for an empty seat
        while (occupied[currentSeat]) {
            currentSeat++;
            if (currentSeat > n) {
                currentSeat = 1; // Wrap around
            }
        }
        
        // Student takes the found seat
        occupied[currentSeat] = true;
        seating[student] = currentSeat;
    }
    
    // Output the seating arrangement
    for (int i = 1; i <= n; i++) {
        cout << seating[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    
    return 0;
}
