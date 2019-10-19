/**
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.
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
    TreeNode* bstFromPreorder(vector<int>& preorder, int i = 0, int border = 0) {    
        if (preorder.size() == 0) return nullptr;
        int rightI = 0;
        int leftI = 0;
        int size = border != 0 ? border : preorder.size();
        border = size;
        // cout << "POINT : " << preorder[i] << endl;
        // cout << "I : " << i << endl;
        // cout << "BORDER : " << border << endl;
        for (int j = i+1; j < size; j++){
           // cout << preorder[j] << " ";
            if (preorder[i] > preorder[j] && leftI == 0){
                leftI = j;
            }
            if (preorder[i] < preorder[j] && rightI == 0){                
                rightI = j;
            }
        }     cout << endl;       
      //  cout << leftI << " " << rightI << endl; 
        TreeNode* root = new TreeNode(preorder[i]);         
        if (leftI == 0)
            root->left = nullptr;
        else {
            if (rightI == 0)
                root->left = bstFromPreorder(preorder, leftI, border);   
            else
                root->left = bstFromPreorder(preorder, leftI, rightI);   
        }
                      
        if (rightI == 0)
            root->right = nullptr;
        else 
            root->right = bstFromPreorder(preorder, rightI, border);
        
        return root;
    }
};