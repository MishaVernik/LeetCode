/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 */
class Solution {
public:
    void help(TreeNode *root, int &h, vector<vector<int>> &ans){
        if (!root) return;
       // cout << root->val << endl;
      // cout << h << endl;
        if ((int)ans.size() <= h){
            ans.push_back(vector<int>{root->val});
        }else
            ans[h].push_back(root->val);    
        h++;
        help(root->left, h, ans);        
        help(root->right, h, ans);
        h--;        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int h = 0;
        if (!root) return ans;
        help(root, h, ans);
        return ans;
        
    }
};