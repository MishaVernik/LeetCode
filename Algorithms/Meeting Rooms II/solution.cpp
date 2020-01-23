
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> x;
        vector<int> y;
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++){
            x.push_back(intervals[i][0]);
            y.push_back(intervals[i][1]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int i = 0;
        int j = 0;
        // 0 5 15
        // 10 20 30
        
        // 2 7
        // 4 10
        
        // 1 13
        // 13 15
        
        // 1 6 13
        // 9 13 15
        int av = 0;
        for (int st : x){
            while (j < y.size() && y[j] <= st){
                j++;
                av++; 
            }
            if (av > 0) av--;
            else ans++;
        }
            
        return ans;
    }
};