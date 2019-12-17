/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
 

Accepted
112,297
Submissions
208,350
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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        unordered_map<int, pair<int,int>> mp;
        mp[root->val] = {k - root->val, -1};
        queue<TreeNode*> q;
        q.push(root);
        int c = 0;
        while (!q.empty()){                    
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto node = q.front();                
                q.pop();
                mp[node->val] = {k - node->val, c++};
                if (node->left != nullptr){
                    q.push(node->left);                    
                }
                    
                if (node->right != nullptr){
                    q.push(node->right);
                }                    
            }
        }
        
        for (auto node : mp){
            if (mp.find(node.second.first) != mp.end()){
                if (mp[node.second.first].second != node.second.second)
                    return true;
            }
                
        }
        return false;
    }
};