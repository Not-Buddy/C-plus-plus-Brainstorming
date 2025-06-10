#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    void push_back(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return; // Handle empty list or single element
        }
        
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void print() {
        if (head == nullptr) {
            cout << endl; // Handle empty list case
            return;
        }
        
        Node* temp = head;
        bool first = true;
        while (temp != nullptr) {
            if (!first) cout << " ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Memory cleanup
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void reverse_linked_list(vector<int>& arr) {
    LinkedList list;
    
    // Handle edge case: empty input
    if (arr.empty()) {
        cout << endl;
        return;
    }
    
    // Build list in original order
    for (int num : arr) {
        list.push_back(num);
    }
    
    // Reverse and print
    list.reverse();
    list.print();
}

int main() {
    int n;
    cin >> n;
    
    // Handle edge case: n = 0
    if (n == 0) {
        cout << endl;
        return 0;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    reverse_linked_list(arr);
    return 0;
}
