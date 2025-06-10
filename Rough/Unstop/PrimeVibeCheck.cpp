#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

string user_logic(ListNode* head) {
    // Step 1: Concatenate digits from linked list
    string num_str = "";
    ListNode* current = head;
    while (current != nullptr) {
        num_str += to_string(current->val);
        current = current->next;
    }
    
    // Step 2: Remove leading zeros by converting to int and back to string
    if (!num_str.empty()) {
        long long num = stoll(num_str);
        num_str = to_string(num);
    } else {
        num_str = "0";
    }
    
    // Step 3: Reverse the number string
    string rev_str = num_str;
    reverse(rev_str.begin(), rev_str.end());
    
    // Step 4: Calculate sum of digits in reversed string
    int digit_sum = 0;
    for (char c : rev_str) {
        digit_sum += (c - '0');
    }
    
    // Step 5: Calculate reversed number - sum
    long long rev_num = stoll(rev_str);
    long long result = rev_num - digit_sum;
    
    // Step 6: Check if result is even or odd
    return (result % 2 == 0) ? "even" : "odd";
}

int main() {
    int N;
    cin >> N;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    string result = user_logic(head);
    cout << result << endl;
    return 0;
}
