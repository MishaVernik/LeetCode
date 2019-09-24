/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
 
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
    void travers(TreeNode** root, int val){
          if (!(*root)) {
            TreeNode *v = new TreeNode(val);
            *root = &*v;
              return ;
        }
        cout << (*root)->val;
        if ((*root)->val > val) return travers(&(*root)->left, val);
        else
            return travers(&(*root)->right, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode **cur = &root;
        // SOLUTION 1
        // while ( *cur ){
        //     if ((*cur)->val > val) cur = &(*cur)->left;
        //     else cur = &(*cur)->right;
        // }
        // *cur = new TreeNode(val);
        // SOLUTION 2
        travers(cur, val);
        return root;
    }
};