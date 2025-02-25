#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullpt) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to insert a node at the end of the linked list
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(ListNode*& head, int val) {
    if (!head) return;

    // If head needs to be deleted
    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* temp = head;
    while (temp->next && temp->next->val != val) {
        temp = temp->next;
    }

    if (temp->next) {
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

// Function to display the linked list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Function to remove the Nth node from the end of the list
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer ahead by n+1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move fast and slow pointers together until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the Nth node
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return dummy->next;
}

// Main function to test the linked list
int main() {
    ListNode* head = nullptr;

    // Insert elements into the linked list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    std::cout << "Original List: ";
    display(head);

    // Remove the 2nd node from the end
    head = removeNthFromEnd(head, 2);
    std::cout << "After Removing 2nd Node from End: ";
    display(head);

    // Delete a node by value
    deleteNode(head, 3);
    std::cout << "After Deleting Node with Value 3: ";
    display(head);

    return 0;
}

