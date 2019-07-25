/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/
/**
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
    void height(TreeNode* root, int h, int& node, int& curH){
        if (!root) return;
        if (root->left == NULL && root->right == NULL && h > curH){
            node = root->val;
            curH = h;
        }
        height(root->left,  h + 1, node, curH);
        height(root->right, h + 1, node, curH);
        // return max(height(root->left),height(root->right)) + 1;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        //int h = height(root);
        int node = 0;
        int curH = 0;
        height(root, 0, node, curH);
        
        return node;        
    }
};