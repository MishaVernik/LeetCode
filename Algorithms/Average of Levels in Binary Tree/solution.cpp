/**
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    void help(TreeNode* root, vector<vector<int>>& levels, int h){
        if (!root) return;
        levels[h].push_back(root->val);
        h++;
        help(root->left, levels, h);
        help(root->right, levels, h);
    }
    int height(TreeNode* root){
        if (!root) return 1;
        return max(height(root->left), height(root->right)) + 1;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int h = height(root)-1;
        vector<vector<int>> levels(h, vector<int>(0));
        vector<double> ans;
        help(root, levels, 0);
        for (auto el : levels){
            double s = 0;
            int cnt = 0;
            for (auto a : el){
                s += a;
                cnt++;
            }            
                ans.push_back(s/(double)cnt);
        }
        
        return ans;
    }
};