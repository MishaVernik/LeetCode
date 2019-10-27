/*We should return its level order traversal:

[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {    
        vector<vector<int>> ans;
        
        if (root == nullptr) return   ans;
        queue<Node*> q; q.push(root);
        
        ans.push_back(  vector<int> {root->val});
        int d = 0;
        while (!q.empty()){   
            d++;
            vector<int> t;
            int len = q.size();
            for (int i = 0; i < len; i++){
                      
                auto child = q.front(); q.pop();
                for (auto el : child->children){
                    if (el){
                        q.push(el);
                        t.push_back(el->val);
                        cout << el->val << endl;
                    }
                }
                 
                
            }
            if (t.size() > 0)
            ans.push_back(t);
           
        }
        return ans;
    }
};
