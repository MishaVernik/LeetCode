/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 
 1. If we dont have a left subtree
 1.1. Go to the right subtree and push to the vector numbers that occurs 
 
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
class Solution {
public:
    int help(TreeNode *root, vector<pair<int,int>> &v, int& h){
        if (!root) return 0;
         h++;
        int r = max(help(root->left, v, h), help(root->right, v,h)) + 1;               
       v.push_back({root->val, h});
        h--;
       return r;
    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        vector<pair<int,int>> v;
        unordered_map<int,int> mp;
        int h = 0;
        help(root, v, h);
        for (auto el : v){
          //  cout << el.first << " " << el.second << endl;
            if (mp.find(el.second) == mp.end()){
                mp[el.second] = el.first;            
          //      cout << el.first << " --- " << el.second << endl;
            }
        }
        v.clear();
        
        vector<int> a;
        for (auto el : mp){
            v.push_back({el.first, el.second});
        }   
        sort(v.begin(), v.end(), [](auto& left, auto& right){
           return left.first < right.first; 
        });
        
        for (auto el : v){
            a.push_back(el.second);
        }
        return a;
        
        
    }
};