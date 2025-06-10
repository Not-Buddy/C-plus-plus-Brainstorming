#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int longest_arithmetic_progression(ListNode* head) {
    // Handle edge cases
    if (!head) {
        return 0;
    }
    if (!head->next) {
        return 1;
    }
    
    int max_len = 1;
    int curr_len = 1;
    ListNode* prev = head;
    ListNode* curr = head->next;
    
    // Initialize with first two elements
    int diff = curr->val - prev->val;
    curr_len = 2;
    max_len = 2;
    
    // Traverse the rest of the linked list
    while (curr->next) {
        int next_diff = curr->next->val - curr->val;
        if (next_diff == diff) {
            // Same difference - extend current AP
            curr_len++;
        } else {
            // Different difference - start new AP
            diff = next_diff;
            curr_len = 2;
        }
        max_len = std::max(max_len, curr_len);
        curr = curr->next;
    }
    
    return max_len;
}

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    int result = longest_arithmetic_progression(head);
    std::cout << result << std::endl;
    
    // Free memory
    current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
