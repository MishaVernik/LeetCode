/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        sort(A.begin(), A.end(), [](vector<int> &l, vector<int> &r){
           return l[0] < r[0]; 
        });
        sort(B.begin(), B.end(), [](vector<int> &l, vector<int> &r){
           return l[0] < r[0]; 
        });
        
        int len1 = (int)A.size();
        int len2 = (int)B.size();
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        bool check = true;
        
        while(i < len1 && j < len2){
                  if (A[i][1] < B[j][0]) ++i;
            else if (B[j][1] < A[i][0]) ++j;
            else {
              ans.push_back({ max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) });
              if (A[i][1] < B[j][1]) ++i;
              else ++j;
            }
        }
        
        return ans;
    }
};