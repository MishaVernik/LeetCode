/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    void travers(TreeNode* root, vector<vector<int>>& ans, int h){
        if (!root) return;
        if (ans.size() <= h) ans.push_back(vector<int>(0,0));                    
        
        if (h % 2 == 0)
            ans[h].push_back(root->val);
        else 
            ans[h].insert(ans[h].begin(), root->val);
        
        travers(root->left , ans, h + 1);
        travers(root->right, ans, h + 1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {    
        vector<vector<int>> ans;        
        travers(root, ans, 0);
        
        return ans;
    }
};