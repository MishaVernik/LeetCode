/**
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int getMaxPath(TreeNode* root, int& max){
        if (root == nullptr) return 0;
        int leftH = getMaxPath(root->left, max);
        if (root->left != nullptr && root->left->val != root->val) leftH = 0;
        int rightH = getMaxPath(root->right, max);      
        if (root->right != nullptr && root->right->val != root->val) rightH = 0;
        max = std::max(max, leftH + rightH);
        return 1 + std::max(leftH, rightH);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int max = 0;
        getMaxPath(root, max);
        return max;
    }
};