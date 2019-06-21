
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class Solution {
public:
     
bool sortbysec( vector<int> &a, 
               vector<int> &b) 
{ 
    return (a[0] < b[0] ); 
} 

vector<vector<int>>merge(vector<vector<int>> &A) {
    if (A.size() == 0) return A;

    sort(A.begin(), A.end(), [](vector<int>& a, vector<int> &b){
       return a[0] < b[0]; 
    });
    int first = 0;
    for (int second = 1; second < A.size(); second++){
        
        if (A[first][1] >= A[second][0]){
            
            A[first][1] = max(A[first][1], A[second][1]);
        }else{
            
            ++first;
            A[first][0] = A[second][0];
            A[first][1] = A[second][1];
        }
    }
    
    A.erase(A.begin() + first + 1, A.end());
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
 
};