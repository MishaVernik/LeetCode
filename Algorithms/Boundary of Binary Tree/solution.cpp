/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
 

Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
 
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
    void get(TreeNode* root, vector<int>& v, map<TreeNode*,int>& mp){
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr){
            cout << root->val << endl;
            if (mp.find(root) == mp.end()){
                    v.push_back(root->val);
                }
            mp[root] = 1;
        }            
        get(root->left, v, mp);
        get(root->right, v, mp);
        
    }
    vector<int> getAllLeaves(TreeNode* root){
        vector<int> leaves;
    //    get(root, leaves);
         return leaves;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto val = q.front(); q.pop();
                if (val->left == nullptr && val->right == nullptr)
                    leaves.push_back(val->val);
                else{
                    if (val->left != nullptr)
                        q.push(val->left);
                    if (val->right != nullptr)
                        q.push(val->right);
                }                    
            }
        }
        return leaves;
    }
    TreeNode* leftMost(TreeNode* root, vector<int>& v, map<TreeNode*,int>& mp){
        if (root == nullptr) return nullptr;
        if (root->left == nullptr) {
            if (mp.find(root) == mp.end()){
                v.push_back(root->val);
            }
            mp[root] = 1;
            return root;
        }
        while (root->left != nullptr || root->right != nullptr){
            if (mp.find(root) == mp.end()){
                v.push_back(root->val);
            }
            mp[root] = 1;
     //        cout << root->val << endl;
            if (root->left == nullptr && root->right == nullptr){
                break;
            }else                
                if (root->left != nullptr)
                    root = root->left;
            else 
                if (root->right != nullptr){
                    root = root->right;
                }
           
        }
  //      cout <<"\nLEFT MOST\n";
    //    cout << root->val << endl;
        if (mp.find(root) == mp.end()){
                v.push_back(root->val);
            }
        mp[root] = 1;
        return root;
    }
    
    TreeNode* rightMost(TreeNode* root,vector<int>& v, map<TreeNode*,int>& mp){
        if (root == nullptr) return nullptr;
        if (root->right == nullptr) {
            if (mp.find(root) == mp.end()){
                v.push_back(root->val);
            }
            mp[root] = 1;
            return root;
        }
        while (root->left != nullptr || root->right != nullptr){
              if (mp.find(root) == mp.end()){
                v.push_back(root->val);
     //              cout << "YES"<< endl;
            }
            mp[root] = 1;
      //       cout << root->val << endl;
            if (root->left == nullptr && root->right == nullptr){
                break;
            }else                
                if (root->right != nullptr)
                    root = root->right;
            else 
                if (root->left != nullptr){
                    root = root->left;
                }
          
        }
     //   cout <<"\RIGHT MOST\n";
      //  cout << root->val << endl;
        if (mp.find(root) == mp.end()){
                v.push_back(root->val);
            }
        mp[root] = 1;
      //  cout << "___________\n";
      //  for (auto el : v)
      //      cout << el << " ";
        return root;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return {};
        map<TreeNode*, int> mp;
        vector<int> ans;
        vector<int> ans1;
        auto l = leftMost(root, ans, mp);  
         get(root, ans, mp);
        auto r = rightMost(root, ans1, mp);
       
        reverse(ans1.begin(), ans1.end());
        for (int i = 0; i < (int) ans1.size(); i++){
             
                ans.push_back(ans1[i]);
             
            
        }
        return ans;
        // 
//[1,2,15,12,10,41,55,233,5,6,7,23,35]
//[1,2,15,12,10,41,55,233,5,6,7,23,35]
     //   [1,2,5,10,41,55,7,3]
       // [1,2,5,10,41,55,7]
        /*
            1. Get left-most node, add them to the vector
            2. Get all leaves, check values that alreay exists and add the rest of them 
                to the vector
            3. Get right-most node 
                reverse vector of these values and delete all values that in the vector
                put the rest of them to the vector        
        */
        
        
    }
};