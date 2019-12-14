/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

 

Example 1:



Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 

Note:

You must return the copy of the given head as a reference to the cloned list.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    void print(Node* head){
        cout << endl;
        while (head != nullptr){
            cout << head->val << " " << head << " "<<  head->next << " " << head->random << endl;
            head = head->next;
        }
    }
    Node* copyRandomList(Node* head) {
       if (head == NULL) return head;
      //  print(head);
       // cout << "=========\n";
        Node *newHead = head;
        while (newHead != nullptr){                            
            Node* clone = new Node(newHead->val, newHead->next, nullptr);
            newHead->next = clone;                    
            newHead = newHead->next->next;            
        }
       // print(head);
     //   cout << "=========\n";
        // 1  2
         // 1  2 - > NULL 
        // 
        newHead = head;
        while (newHead != nullptr){   
            if (newHead->random != nullptr){
                newHead->next->random = newHead->random->next;    
            }            
            newHead = newHead->next->next;
        }        
        newHead = head;
        Node* cloneH = head->next;
        Node* clone = cloneH;
        while (clone != nullptr){
            newHead->next = clone->next;
            clone->next = clone->next == NULL ? NULL : clone->next->next;
            newHead = newHead->next;
            clone = clone->next;                        
        }     
        return cloneH;
    }
};