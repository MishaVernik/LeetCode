/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
       if (head == NULL)
           return NULL;
        
        while (head != NULL && head->next != NULL && head->val == val) {
            ListNode *tmp = head->next;
            head = tmp;        
        }
         ListNode *node = head;
        while (node != NULL && node->next != NULL){                
            while (node != NULL && node->next != NULL &&  node->next->val == val){
                node->next = node->next->next;                
            }
            node = node->next;
        }
        
        if (head->val == val)
            return NULL;
        return head;
     }
};