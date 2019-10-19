/*
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
 *
 */



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long, long long>> A;
         
        for (int i = 0; i < (int)nums.size(); i++) A.push_back({nums[i], i});
        sort(A.begin(), A.end(), [](auto& l, auto& r){           
            return l.first < r.first;
        }); 
        // for (auto el : A)
        //     cout << el.first << " " << el.second << endl;
        for (int i = 0; i < nums.size(); i++){
            int l = i;
            int r = nums.size();
            while (l < r){
                int mid = l + (r - l) / 2;
                if (mid != i && A[mid].second != A[i].second && (A[mid].first - A[i].first )<= t && abs(A[mid].second - A[i].second) <= k) {
                   // cout << "----\n" <<  A[mid].first << " " <<  A[i].first << endl << "--> " << A[mid].second << " "<< A[i].second << endl;
                   //  cout << i << " " << mid;
                    return true;
                }
                    
                if (A[mid].first > t + A[i].first){
                    r = mid;
                }else
                    l = mid + 1;
            }
        }
       
        // SOLUTION 1
        /*
        
            O(n^2)
            for i = 0
                for j = i + 1
                    if (diff1 <= t && diff2 <= k)
                    return true
                    
            return false
            
            SOLUTION 2
            O(N log N)
           0 1 2 3 
           1 2 3 1
           
           0 3 1 2           
           1 1 2 3
           
            t = 0, k = 3            
            a[i] - a[j] <= t -> a[i] <= t + a[j]
            i - j <= k -> i <= k + j
            
            mp1                     ind
            t + a[0] = 0 + 1 = 1 | 0 + k = 0 + 3 = 3 
            t + a[1] = 0 + 2 = 2 | 1 + k = 1 + 3 = 4
            t + a[2] = 0 + 3 = 3 | 2 + k = 2 + 3 = 5
            t + a[3] = 0 + 1 = 1 | 3 + k = 3 + 3 = 6
            
           if (mp[i] >= a[i] && mp2[i] - k != i && mp2[i] >= i) 
                
        // */     
        // long long int k1 = k;
        // long long int t1 = t;
        // for (long long i = 0; i < nums.size(); i++){
        //     for (long long j = i + 1; j < nums.size(); j++){
        //         if (j - i <= k1 && abs(nums1[j]/. - nums1[i]) <= t1){
        //             return true;
        //         }
        //     }
        // }
        return false;
    }
};
