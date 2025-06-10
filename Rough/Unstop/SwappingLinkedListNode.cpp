#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    // Find the kth node from the beginning
    ListNode* first = head;
    for (int i = 0; i < k - 1; i++) {
        first = first->next;
    }

    // Use two pointers to find kth node from the end
    ListNode* slow = head;
    ListNode* fast = first;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Swap values
    int temp = first->val;
    first->val = slow->val;
    slow->val = temp;

    return head;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::cin >> k;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;

    ListNode* modified_head = swapNodes(head, k);

    current = modified_head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
