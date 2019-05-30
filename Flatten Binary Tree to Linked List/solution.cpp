/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
Last Submission

 */
class Solution {
public:
    void extra(TreeNode* node){
        
        if( node == NULL)
            return;
        extra(node->left);                 
        extra(node->right);
        
       // cout << "RIGHT:"<<node->val << endl;
        if (node->left != NULL && node->right != NULL){
          //  cout << "here\n";
            TreeNode* tmp = node->right;        
            node->right = node->left;
            node->left = NULL;
            while (node->right != NULL && node->right->right != NULL) node = node->right;
            if (node->right == NULL){
                node->right = tmp;
            }else
                node->right->right = tmp;  
            
         //  print(root);
         // cout << endl;   
        }else
            if (node->left != NULL && node->right == NULL){                         
                    node->right = node->left;                    
                    node->left = NULL;
             //   cout << "1 NULL \n";
         //  print(root);
        //  cout << endl;   
            }
        
        
    }
    void print(TreeNode *root){
        
        if (root == NULL)
            return;
         
        print(root->left);      
        print(root->right);
        cout << root->val;
    }
    void flatten(TreeNode* root) {
        // print(root);
        if (!root) return;
        extra(root);       
    }
};