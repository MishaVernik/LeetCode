/*
 not turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 
 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*
            1. Sort by 2 element
            2. 
        */
 
        cout << 1;
        vector<pair<int,int>> s;
        vector<pair<int,int>> e;
        for (auto el : trips){
            s.push_back({el[1], el[0]});
            e.push_back({el[2], el[0]});
        }
        sort(s.begin(), s.end(), [](auto& x, auto& y){
            return x.first < y.first;
        });
        sort(e.begin(), e.end(), [](auto& x, auto& y){
            return x.first < y.first;
        });
        // 1 3
        // 5 7
        int i = 0;
        int j = 0;  
        int cap = 0;
        while (1){
           if (i  >= s.size() && j + 1 >= s.size()){
                break;
            }
             while (i < s.size() && s[i].first < e[j].first){
                if (cap + s[i].second > capacity) return false;
                cap += s[i].second;
                i++;   // cout << 1;
            }
            if (i >= s.size() && cap <= capacity) return true;
            while (j  < s.size() && s[i].first >= e[j].first){
                if ( cap - e[j].second < 0) return false;
                cap -= e[j].second;
                j++;  //  cout << 2;
            }
            
        }                
        return true;
    }
};