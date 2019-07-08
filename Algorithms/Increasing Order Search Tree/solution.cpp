/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
 
*/
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
     ///   vector<int> &a = nums1.size() < nums2.size() ? nums1 : nums2;
     ///   vector<int> &b = nums1.size() < nums2.size() ? nums2 : nums1;
        vector<int> ans;
        int lenA = a.size();
        int lenB = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        bool isNew = true;
        int r = 0;
      //  cout << lenA << " " << lenB << endl;
        while (i < lenA && j < lenB){
          //  cout << a[i] << " " << b[j] << endl;
          //  cout << i << " " << j << endl;
            r = a[i];
            while (i < lenA && j < lenB && a[i] == b[j]){
                if (a[i] != r) {
                    r = a[i];
                    isNew = true;
                }
                if (isNew){
                    ans.push_back(b[j]);
                }
                isNew = false;
                i++;
                j++;    
            }
            
            if (i < lenA && j < lenB && a[i] < b[j]) 
                i++;
            else 
                j++;
            
            isNew = true;            
        }
        
        return ans;
    }
};