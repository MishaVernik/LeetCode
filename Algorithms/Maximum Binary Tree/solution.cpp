/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
 
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int mx = 0;
        int ind = 0;
        for (int i = 0; i < nums.size(); i++){
            if (mx < nums[i]){
                mx = nums[i];
                ind = i;
            }
        }
        TreeNode* root = new TreeNode(mx);
        vector<int> l(nums.begin(), nums.begin() + ind);
        vector<int> r(nums.begin() + ind + 1, nums.end());
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);
        
        return root;
    }
};