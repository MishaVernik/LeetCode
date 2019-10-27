/*
 *Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 

Return its postorder traversal as: [5,6,3,2,4,1].

 
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
    vector<int> postorder(Node* root) {
        if (root == nullptr) return vector<int>();
        stack<Node*> st; st.push(root);
        vector<int> ans;
        while (!st.empty()){
            auto child = st.top(); st.pop();
            for (auto el : child->children) if (el) st.push(el);
            ans.push_back(child->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
