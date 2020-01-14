
/*
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/
class StringIterator {
private:
    int i, k;
    string s;
    vector<pair<char, long long>> q;
public:
    StringIterator(string S) {
        i = 0;
        k = 1;
        int j = 0;
        s = "";
        
        while (j < S.length()){
            int prev = j;
            string num = "";
            j++;
           
            while (j < S.length() && isalpha(S[j]) == false){
                num += S[j++];
            }
            
            q.push_back({S[prev], stoll(num)});                        
        }        
    }
    
    char next() {
        if ( i >= q.size()) return ' ';
        if (k >= q[i].second){
            k = 1;
            i++;
            return q[i-1].first;
        }else 
            k++;
        return q[i].first;
    }
    
    bool hasNext() {
        if (i >= q.size()) return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


public class StringIterator {
    String res;
    int ptr = 0, num = 0;
    char ch = ' ';
    public StringIterator(String s) {
        res = s;
    }
    public char next() {
        if (!hasNext())
            return ' ';
        if (num == 0) {
            ch = res.charAt(ptr++);
            while (ptr < res.length() && Character.isDigit(res.charAt(ptr))) {
                num = num * 10 + res.charAt(ptr++) - '0';
            }
        }
        num--;
        return ch;
    }
    public boolean hasNext() {
        return ptr != res.length() || num != 0;
    }
}
