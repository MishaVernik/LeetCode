/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
class Solution {
public:    
   void print(ListNode *head){
       while (head){
           cout << head->val << " " ;
           head = head->next;
       }
       cout << endl;
   }
    ListNode* swapPairs(ListNode* head) {
      if(!head) return NULL;
        ListNode tmp(0);
        ListNode *t = head;
        tmp.next = head;
        ListNode *pre = &tmp, *cur = head;
        while(cur && cur->next){
          //    print(&tmp);
           // cout << "pre : " << pre->val << " cur : " << cur->val << endl;
            pre->next = cur->next;
          //  cout << "pre->next : " << pre->val << " cur->next : " << cur->val << endl;
            pre = pre->next;
          //  cout << "pre : " << pre->val << " pre->next : " << pre->next->val << endl;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
          
        }
        //  print(&tmp);
        return tmp.next;
    }
};