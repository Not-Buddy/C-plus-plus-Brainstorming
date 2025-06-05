#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int minChanges(Node* head, int n) {
    // Convert linked list to vector for easier manipulation
    std::vector<int> original;
    Node* current = head;
    
    // Extract values from linked list
    while (current != nullptr) {
        original.push_back(current->val);
        current = current->next;
    }
    
    // Create sorted version
    std::vector<int> sorted_array = original;
    std::sort(sorted_array.begin(), sorted_array.end());
    
    // Count positions where values differ
    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (original[i] != sorted_array[i]) {
            changes++;
        }
    }
    
    return changes;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    
    Node* head = new Node(values[0]);
    Node* temp = head;
    for (int i = 1; i < n; ++i) {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    
    int result = minChanges(head, n);
    std::cout << result << std::endl;
    
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    
    return 0;
}
