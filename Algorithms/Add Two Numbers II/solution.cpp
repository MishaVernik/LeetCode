/**
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
 */
/**
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int size(ListNode* l){
        int i = 0;
        while (l != nullptr) {
            i++;
            l = l->next;
        }
        return i;
    }
public:
    pair<ListNode*, int> fun(ListNode* l1, ListNode* l2,int i1, int i2, int sz1, int sz2) {        
        if (l1 == nullptr && l2 == nullptr) return {nullptr, 0};
        pair<ListNode*, int> l;
        if (i1 > i2 && i1 > 0 && i2 > 0){
            l = fun(l1->next, l2,i1-1, i2, sz1,sz2);
        }else
            if (i2 > i1 && i1 > 0 && i2 > 0){
                l = fun(l1, l2->next,i1,i2-1,sz1,sz2);
            }else if (i1 > 0 && i2 > 0){
                l = fun(l1->next, l2->next,i1-1,i2-1,sz1,sz2);
            }
        cout << l1->val << " " << l2->val << " " << l.second << "\n ";
        ListNode* ans = new ListNode((l1->val + l2->val + l.second) % 10);
        int c = (l1->val + l2->val + l.second) / 10;
        l1->val = 0;
        l2->val = 0;
        ans->next = l.first;
        return {ans, c};
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {        
        int sz1 = size(l1);
        int sz2 = size(l2);                   
        auto l = fun(l1,l2,sz1,sz2,sz1,sz2);
        if (l.second == 1){
            ListNode* lst = new ListNode(1);
            lst->next = l.first;
            return lst;
        }
        return l.first; 
    }
};