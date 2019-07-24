/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    
    void travers(vector<vector<int>>& v, TreeNode* root, int h, int curHeight){
        if (!root) return;
        //cout << h - curHeight << endl;
        v[h-curHeight].push_back(root->val);
        travers(v, root->left,  h, curHeight + 1);
        travers(v, root->right, h, curHeight + 1);
        
    }
    int height(TreeNode* root){
        if (!root) return 1;
        return max(height(root->left),height(root->right)) + 1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>(); 
        int h = height(root);
        vector<vector<int>> v(h-1,vector<int>(0));            
        travers(v, root, h-1, 1);
        return v;
    }
};