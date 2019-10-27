/*
 *Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [1,3,5,6,2,4].

 

Note:

Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<Node*> st; st.push(root);
        while (!st.empty()){
            auto child = st.top(); st.pop();
            for (int i = child->children.size() - 1; i >= 0 ; i--) if (child->children[i]) st.push(child->children[i]);
            ans.push_back(child->val);
        }
        
        return ans;
    }
};
