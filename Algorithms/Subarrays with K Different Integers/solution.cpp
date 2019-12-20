/*
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
 */
const auto l = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
}();

class Window{
private:
    unordered_map<int, int> count;    
public:
    Window(){
        count.clear();
    }
    
    void add(int x){
        count[x]++;
    }
    
    void remove(int x){
        count[x]--;
        if (count[x] == 0)
            count.erase(x);
    }
    
    int different(){
        return count.size();
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // Solution 1
        int ans = 0;
        int left1 = 0;
        int left2 = 0;
        Window w1;
        Window w2;
        for (int right = 0; right < A.size(); right++){
            int x = A[right];
            w1.add(x);
            w2.add(x);
            while (w1.different() > K)
                w1.remove(A[left1++]);
            while (w2.different() >= K)
                w2.remove(A[left2++]);
            
            ans = ans + (left2 - left1);
            
        }
        return ans;
        // Solution 2
//         int ans = 0;
//         for (int i = 0; i < A.size(); i++){
//             map<int, vector<int>> mp;
//             for (int j = 0; j <= i;j++){
//                 if (mp.find(A[j]) == mp.end())
//                     mp[A[j]] = vector<int>{A[j]};
//                 else 
//                     mp[A[j]].push_back(A[j]);
//             }
            
//             int num = mp.size();
//             if (num == K)
//                 ans++;
//             for (int j = i + 1; j < A.size(); j++){
//                 if (mp.find(A[j - i - 1]) != mp.end()){
//                     if (mp[A[j-i-1]].size() == 1){
//                         mp.erase(A[j-i-1]);
//                     }else
//                         mp[A[j-i-1]].pop_back();
//                 }
//                 if (mp.find(A[j]) == mp.end()){
//                     mp[A[j]] = vector<int>{A[j]};
//                 }else{
//                     mp[A[j]].push_back(A[j]);
//                 }
            
//                 num = mp.size();
//             if (num == K)
//                 ans++;
//             }
             
//         }
//        return ans;
    }
};