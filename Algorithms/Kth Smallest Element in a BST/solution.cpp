/*
 *Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */
const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
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
    void find(TreeNode* root, int& k, int& ans){
        if (!root || ans != INT_MAX) return ;

        find(root->left, k, ans);
         k--;
       // cout << root-> val << " k :" << k << " ";
       if (k == 0) {ans = root->val; return;}
        find(root->right, k, ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int ans = INT_MAX;
        find(root, k, ans);
        return ans;
    }
};
