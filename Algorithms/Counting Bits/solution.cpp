/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
class Solution {
public:
    int count(int n){
        int ans = 0;
        while (n > 0){
            if (n % 2 == 1)
                ans++;
            n /= 2;
        }
        return ans;
    }
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);   
        int offset = 1;
        for (int i = 1; i <= num; i++){
           // cout << count(i) << " ";
           // if (i % 10 == 0) cout << endl;
             if (offset * 2 == i){
            offset *= 2;
        }
        ans[i] = ans[i - offset] + 1;
            //ans.ush_back(count(i));
        }
        return ans;
    }
};
/*0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 
2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 
2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 
2 3 3 4 */