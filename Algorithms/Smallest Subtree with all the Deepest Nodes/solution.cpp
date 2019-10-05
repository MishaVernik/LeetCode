/*
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:



We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.
 

Note:

The number of nodes in the tree will be between 1 and 500.
The values of each node are unique.
*/
const int ZERO = [](){
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
public:
    
    int maxDepth(TreeNode* node)  
    {  
        if (node == NULL)  
            return 0;  
        else
        {  
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->left);  
            int rDepth = maxDepth(node->right);  

            /* use the larger one */
            if (lDepth > rDepth)  
                return(lDepth + 1);  
            else return(rDepth + 1);  
        }  
    }  
    
    int minDepth(TreeNode *root) 
    { 
        // Corner case. Should never be hit unless the code is  
        // called on root = NULL 
        if (root == NULL) 
            return 0; 

        // Base case : Leaf Node. This accounts for height = 1. 
        if (root->left == NULL && root->right == NULL) 
            return 1; 

        // If left subtree is NULL, recur for right subtree 
        if (!root->left) 
            return minDepth(root->right) + 1; 

        // If right subtree is NULL, recur for left subtree 
        if (!root->right) 
            return minDepth(root->left) + 1; 

        return min(minDepth(root->left), minDepth(root->right)) + 1; 
    } 
    
    void travers(TreeNode* root, int d, int depth, int& ans){
        if (!root || ans != -1) return ;
        
     //  cout <<"val : " <<root->val << "\n MAX: " << maxDepth(root) << "\n MIN: " << minDepth(root)  << "\n d: " << d << endl;    
        if (maxDepth(root->left) + d + 1 == depth && maxDepth(root->right) + d + 1 == depth){
            ans = root->val;
            return ;
        }
        travers(root->left, d + 1, depth, ans);
        travers(root->right, d + 1, depth, ans);                        
    }
    
    TreeNode* find(TreeNode* root, int val){
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode* l = find(root->left, val);
        TreeNode*r =  find(root->right, val);        
        if (r !=nullptr && r->val==val) return r;
        if (l !=nullptr && l->val==val) return l;
        return nullptr;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       // SOLUTION 1  
       //   if (!root) return nullptr;
       //  int d = maxDepth(root);
       // // cout << d << endl;
       //  int ans = -1;
       //  travers(root, 0, d, ans);
       //  // SOLUTION 2:
        if (!root) return nullptr;
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        if (lHeight == rHeight) return root;
        if (lHeight > rHeight) return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
        //return find(root, ans);
    }
};