#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

void user_logic(LinkedList& linkedList) {
    if (linkedList.head == nullptr) return;
    
    // Collect nodes into 3 groups based on position % 3
    std::vector<Node*> groups[3];
    Node* current = linkedList.head;
    int position = 0;
    
    while (current != nullptr) {
        groups[position % 3].push_back(current);
        current = current->next;
        position++;
    }
    
    // Reconstruct the linked list by connecting groups in order
    linkedList.head = nullptr;
    linkedList.tail = nullptr;
    
    for (int i = 0; i < 3; i++) {
        for (Node* node : groups[i]) {
            node->next = nullptr; // Reset the next pointer
            if (linkedList.head == nullptr) {
                linkedList.head = node;
                linkedList.tail = node;
            } else {
                linkedList.tail->next = node;
                linkedList.tail = node;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    LinkedList list;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        list.push(element);
    }

    user_logic(list);
    list.printList();

    return 0;
}
