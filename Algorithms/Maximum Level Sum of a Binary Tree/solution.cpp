/*

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:



Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 

Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
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
    vector<int> sum;
    void dfs(TreeNode* root, int lvl){
        if (!root) return;
        if (sum.size())
        dfs(root->left, lvl + 1);
        dfs(root->left, lvl + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        int d = 0;
        vector<pair<int,int>> v; v.push_back({root->val, 1});
        while (!q.empty()){
            d++;
            int len = q.size();
            for (int i = 0; i < len; i++){
                auto el = q.front(); q.pop();
              //  cout << d << " \n";
                if (el->left != nullptr){
                    if (v.size() <= d){
                            v.push_back({el->left->val, d + 1});
                        }else v[d].first += el->left->val;
                        q.push(el->left);
                }
                if (el->right  != nullptr){
                    if (v.size() <= d){
                            v.push_back({el->right->val, d + 1});
                        }else v[d].first += el->right->val;
                        q.push(el->right);
                }                
            }
        }
        
        int ind = INT_MAX;
        int mx = INT_MIN;
        for(auto el : v) {
            cout << el.first << " " << el.second << endl;
             
            if (mx < el.first){
                mx = el.first;
                ind = el.second;
            } else if (mx == el.first && ind > el.second) ind = el.second;
        }
          
        return ind;
    }
};