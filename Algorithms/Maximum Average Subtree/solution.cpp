/*
Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)

 

Example 1:



Input: [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
 

Note:

The number of nodes in the tree is between 1 and 5000.
Each node will have a value between 0 and 100000.
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
 
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
private:
    pair<int,int> sum(TreeNode* root, double& ans ){
        if (!root) return {0, 0};
    
        pair<int,int> leftSum =  sum(root->left, ans);
        pair<int,int> rightSum = sum(root->right, ans);    
        ans = max(ans, (double)leftSum.first / (double)leftSum.second);
        ans = max(ans, (double)rightSum.first / (double)rightSum.second);
        ans = max(ans, (double)(root->val + leftSum.first + rightSum.first) 
                  / (double)(1 + leftSum.second + rightSum.second ));
        
        return {root->val + leftSum.first + rightSum.first, 1 + leftSum.second + rightSum.second };
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        if (!root) return 0;
        double ans = 0;
        auto s = sum(root, ans);
        return ans;
    }
};