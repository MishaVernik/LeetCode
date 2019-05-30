/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */
class Solution {
public:
    void help(TreeNode *root, vector<int> &s){
        
        if (root == NULL) return ;
       
        help(root->left, s);
         s.push_back(root->val);
        help(root->right, s);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> s;    
        if (root == NULL) return s;
               
         
         help(root, s);
     
        return s;
        
    }
};