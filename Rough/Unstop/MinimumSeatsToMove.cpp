#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // for sort

int calculate_min_moves(std::vector<int> seats, std::vector<int> students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int moves = 0;
    int n = seats.size();
    for (int i = 0; i < n; i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seats(n);
    std::vector<int> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seats[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i];
    }
    int result = calculate_min_moves(seats, students);
    std::cout << result << std::endl;
    return 0;
}

