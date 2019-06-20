/**
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void greater(TreeNode* root, int val, int &sum){
        if (!root) return ;
        if (root->val > val){
            sum += root->val;            
        }
        greater(root->left, val, sum);
        greater(root->right, val, sum);
    }
    void help(TreeNode* node, TreeNode* root, unordered_map<int,int>& mp){
        if (!node) return;
        help(node->left, root, mp);
        int sum = 0;
        greater(root, node->val, sum);
        mp[node->val] = node->val + sum;
        help(node->right, root, mp);
    }
    int sum = 0;
    void help1(TreeNode* root, unordered_map<int,int> mp){
        if (!root) return;
        root->val = mp[root->val];
        help1(root->left, mp);
        help1(root->right, mp);
    }
    
    TreeNode* convertBST(TreeNode* root) {
       // if (!root) return nullptr;
       //  unordered_map<int,int> mp;
       //  help(root, root, mp);
       //  help1(root, mp);
       //  return root;
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};