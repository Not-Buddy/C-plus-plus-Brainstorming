#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* user_logic(Node* head) {
    // Handle empty list
    if (!head) {
        return nullptr;
    }
    
    Node* current = head;
    
    // Traverse the linked list
    while (current && current->next) {
        if (current->val == current->next->val) {
            // Found duplicate - skip the next node
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; // Free memory of duplicate node
        } else {
            // No duplicate - move to next node
            current = current->next;
        }
    }
    
    return head;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    Node* updated_head = user_logic(head);

    if (!updated_head) {
        cout << 0 << endl;
    } else {
        vector<int> result;
        current = updated_head;
        while (current) {
            result.push_back(current->val);
            current = current->next;
        }
        cout << result.size() << endl;
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
