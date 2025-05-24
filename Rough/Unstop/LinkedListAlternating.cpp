#include <iostream>
#include <vector>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    void push(int data) {
        Node *new_node = new Node{data, nullptr};
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
};

int user_logic(LinkedList &list) 
{
    if(!list.head||!list.head->next) return 1;

    Node *prev=list.head;
    Node *curr=list.head->next;
    
    int last_dir=0;
    if(curr->data>prev->data) last_dir=1;
    else if(curr->data<prev->data) last_dir=-1;
    else return 0;

    prev=curr;
    curr=curr->next;

    while(curr)
    {
        int dir=0;
        if(curr->data>prev->data) dir=1;
        else if(curr->data<prev->data) dir=-1;
        else return 0;

        if(dir==last_dir) return 0;
        last_dir=dir;
        prev=curr;
        curr=curr->next;
    }


    // Implement your logic here
    return 1;
}
int main() {
    int n;
    std::cin >> n;
    LinkedList ll;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        ll.push(value);
    }
    int result = user_logic(ll);
    std::cout << result << std::endl;
    return 0;
}
