/*Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
 

Note:

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
 
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        bool isZero = false;
        for (auto& el : A){
            if (k > 0 && el < 0){
                k--;
                el *=-1;
            }
         }
        int m = 0;
        int index = 0;
        if (k > 0){
            m = A[0];
            for (int i = 0 ;i  < A.size(); i++){
                if (m > A[i]){
                    m = A[i]; 
                    index=i;
                }
                
            }
            if (k % 2 == 0) m = abs(m);
            else m = -abs(m);
        }
        
        int sum = m;
        for (int i = 0; i < A.size(); i++){
            if (i == index && m != 0) continue;
            sum +=A[i];
        }
        return sum;
    }
};