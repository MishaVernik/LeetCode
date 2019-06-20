/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//       map<vector<pair<int,int>>, int> mp;
//       vector<vector<int>> ans;
//       set<vector<int>> st;
//         for (int i = 0; i < (int)nums.size(); i++){
//             for (int j = i + 1; j < (int)nums.size(); j++){    
//                 vector<pair<int,int>> d;
//                 d.push_back({nums[i], i});
//                 d.push_back({nums[j], j});
//                 mp[d] = 1;
//             }
//         }
        
//         for (int i = 0; i < (int)nums.size(); i++){
//             for (auto el : mp){
//                 if (el.first[0].first + el.first[1].first + nums[i] == 0 && el.first[0].second != i && el.first[1].second != i){ 
//                     vector<int> d;
//                     int a = el.first[0].first;
//                     int b = el.first[1].first;
//                     int c = nums[i];
//                     if (a >= b && a >= c){
//                         if (b >= c){
//                             d = {a,b,c};
//                         }else{
//                             d = {a,c,b};
//                         }
//                     }
//                     if (b >= a && b >= c){
//                         if (a >= c){
//                             d = {b,a,c};
//                         }else{
//                             d = {b,c,a};
//                         }
//                     }
//                     if (c >= b && c >= a){
//                         if (a >= b){
//                             d = {c,a,b};
//                         }else{
//                             d = {c,b,a};
//                         }
//                     }
//                     if (st.find(d) == st.end()){
//                         st.insert(d);         
//                         ans.push_back(d);
//                     }
                    
//                 }
//             }
//         }
  
        
//         return ans;
    
//  SECOND SOLUTION 
        
//        set<vector<int>> st;
//    vector<vector<int>> ans;
//     int n = (int)nums.size();
//     for (int i=0; i<n-1; i++) 
//     { 
//         // Find all pairs with sum equals to 
//         // "-arr[i]" 
//         unordered_set<int> s; 
//         for (int j=i+1; j<n; j++) 
//         { 
//             int x = -(nums[i] + nums[j]); 
//             if (s.find(x) != s.end()) 
//             { 
//                 //printf("%d %d %d\n", x, nums[i], nums[j]); 
//                 vector<int> d;
//                     int a = x;
//                     int b = nums[j];
//                     int c = nums[i];
//                     if (a >= b && a >= c){
//                         if (b >= c){
//                             d = {a,b,c};
//                         }else{
//                             d = {a,c,b};
//                         }
//                     }
//                     if (b >= a && b >= c){
//                         if (a >= c){
//                             d = {b,a,c};
//                         }else{
//                             d = {b,c,a};
//                         }
//                     }
//                     if (c >= b && c >= a){
//                         if (a >= b){
//                             d = {c,a,b};
//                         }else{
//                             d = {c,b,a};
//                         }
//                     }
//                 if (st.find(d) == st.end()){
                 
//                        st.insert(d);     
//                      ans.push_back(d);
//                 }
                 
//             } 
//             else
//                  s.insert(nums[j]); 
//             } 
//         } 
        
        // sort array elements 
    sort(nums.begin(), nums.end()); 
  set<vector<int>> st;
   vector<vector<int>> ans;
         int n = (int)nums.size();
    for (int i=0; i<n-1; i++) 
    { 
        // initialize left and right 
        int l = i + 1; 
        int r = n - 1; 
        int x = nums[i]; 
        while (l < r) 
        { 
            if (x + nums[l] + nums[r] == 0) 
            { 
                // print elements if it's sum is zero 
                //printf("%d %d %d\n", x, arr[l], arr[r]); 
                 vector<int> d;
                    int a = x;
                    int b = nums[l];
                    int c = nums[r];
                    if (a >= b && a >= c){
                        if (b >= c){
                            d = {a,b,c};
                        }else{
                            d = {a,c,b};
                        }
                    }
                    if (b >= a && b >= c){
                        if (a >= c){
                            d = {b,a,c};
                        }else{
                            d = {b,c,a};
                        }
                    }
                    if (c >= b && c >= a){
                        if (a >= b){
                            d = {c,a,b};
                        }else{
                            d = {c,b,a};
                        }
                    }
                if (st.find(d) == st.end()){
                 
                      st.insert(d);     
                     ans.push_back(d);
                }
                l++; 
                r--; 
               // found = true; 
            } 
  
            // If sum of three elements is less 
            // than zero then increment in left 
            else if (x + nums[l] + nums[r] < 0) 
                l++; 
  
            // if sum is greater than zero than 
            // decrement in right side 
            else
                r--; 
        } 
    } 
        
        return ans;
    }
};