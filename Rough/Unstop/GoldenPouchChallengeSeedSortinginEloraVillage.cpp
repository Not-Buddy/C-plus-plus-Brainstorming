#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
};

Node* user_logic(int k, int n, const vector<int>& seeds) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    int i = 0;
    while (i < n) {
        // Create current group
        vector<int> group;
        for (int j = i; j < min(i + k, n); j++) {
            group.push_back(seeds[j]);
        }
        
        if (group.size() == k) {
            // Full group - calculate floor average
            int sum = 0;
            for (int val : group) {
                sum += val;
            }
            int avg = sum / k;  // Integer division gives floor
            
            if (avg % 2 == 0) {
                // Even average - add to linked list
                Node* new_node = new Node(avg);
                if (head == nullptr) {
                    head = new_node;
                    tail = new_node;
                } else {
                    tail->next = new_node;
                    tail = new_node;
                }
            }
            // Odd average - discard (do nothing)
        } else {
            // Partial group - add all seeds individually
            for (int val : group) {
                Node* new_node = new Node(val);
                if (head == nullptr) {
                    head = new_node;
                    tail = new_node;
                } else {
                    tail->next = new_node;
                    tail = new_node;
                }
            }
        }
        i += k;
    }
    
    return head;
}

void print_linked_list(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << " null" << endl;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> seeds(n);
    for (int i = 0; i < n; ++i) {
        cin >> seeds[i];
    }
    
    // Call user logic function
    Node* head = user_logic(k, n, seeds);
    
    // Print the linked list
    print_linked_list(head);
    return 0;
}
