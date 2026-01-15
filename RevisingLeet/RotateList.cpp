/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || !head->next || k == 0) return head;

      ListNode* curr = head;
      int len = 0;
      while(curr) {len++; curr = curr->next;}
      k=k%len;

      if(k==0) return head;

      for(int i{0}; i<k; i++)
      {
            ListNode *prev = nullptr;
            ListNode *tail = head;

            while(tail->next != nullptr)
            {
                prev = tail;
                tail = tail->next;
            }        

            tail->next = head;
            prev->next = nullptr;
            head = tail;
      }
      return head;
    }
};
