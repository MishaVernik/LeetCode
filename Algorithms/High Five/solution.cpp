/*
Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores
 
*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        /*
            <key, value>
            1. Put all these values into hasmap 
                1.1 Hashmap contains key - id 
                                     value = pair<sum, quantity>
            2. Put all of these data into vector<pair<double, int>> 
                2.1 first value = AVG(SUM)
                    second value = index            
            3. Sort by ascedning and get first 5 elements
        
        */
        vector<vector<int>> ans;
        map<double, int> res;
        map<int, priority_queue<int>> mp;
        for (auto el : items){
            mp[el[0]].push(el[1]);            
        }
        
        for (auto el : mp){            
            int cnt = 0;
            double sum = 0;
            while (cnt < 5){
                sum += el.second.top();
                el.second.pop();
                cnt++;
            }            
            
            ans.push_back({el.first, (int)((double)sum / 5.0)});
        }
            
        return ans;
    }
};