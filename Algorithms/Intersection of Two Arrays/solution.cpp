/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 
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