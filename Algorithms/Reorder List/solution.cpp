/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 Given a singly linked list L: L0?L1?�?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?�

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 */
class Solution {
public:
    
    ListNode *find(ListNode *head, int val){  
        int i = 0;
        while (i+1 != val && head){
            head = head->next;
            i++;
        }        
        return head;
    }
    int size(ListNode *head){
        int sum = 0;
        
        while(head){
            cout << head->val << " ";
            head = head->next;
            sum++;
        }
        cout << endl;
        return sum;
    }
    void reorderList(ListNode* head) {
    
       if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
    
    //for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
    }    
};