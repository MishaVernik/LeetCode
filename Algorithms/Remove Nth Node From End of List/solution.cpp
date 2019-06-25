/**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        int size = 0;
        while (slow != nullptr){
            slow = slow->next;
            size++;
        }
      //  cout << slow->val ;
        int i = 0;
        cout << size;
        while (i < size - n - 1){
            fast = fast->next;
            i++;
        }
        if (size - n - 1 < 0){   
            ListNode* t = head;
            t = head->next;
            head = t;
            //head->next = head->next->next;
        }else
            fast->next = fast->next->next;
       // cout << fast->val;
        return head;
    }
};