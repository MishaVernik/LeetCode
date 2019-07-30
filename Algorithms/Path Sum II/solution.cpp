/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void travers(TreeNode* root, vector<int>& v,vector<vector<int>>& ans, int sum){
        if (!root) return;
        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum - root->val == 0){
            ans.push_back(v);            
        }     
        travers(root->left, v, ans, sum - root->val);
       
        travers(root->right, v, ans, sum - root->val); v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> v;
        travers(root, v, ans, sum);
        return ans;
    }
};