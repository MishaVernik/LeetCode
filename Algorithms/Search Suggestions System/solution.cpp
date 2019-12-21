/*
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
 

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters
*/
class Node{
public:
    bool end;
    vector<Node*> letters;
    
    Node(): end(false), letters(26, nullptr){}
};

class Trie{    
public:
    Node* head = new Node();
    Trie(){
        
    }
    
    void addWord(string& s){
        Node* current = head;
        for (auto c : s){
            if (current->letters[c-'a'] == nullptr) current->letters[c-'a'] = new Node();
            current = current->letters[c-'a'];
        }
        current->end = true;
    }
    
    vector<string> wordsBeginWith(string& prefix){
        vector<string> result;
        Node* current = head;
        for (char c : prefix){
            if (current->letters[c-'a'] == nullptr) return {};
            current = current->letters[c-'a'];
        }
        dfs(current, result, prefix);
        return result;
    }
    
    void dfs(Node* current, vector<string>& res, string& wordAfterPrefix){
        if (res.size() >= 3) return;
        if (current->end) res.push_back(wordAfterPrefix);
        for (int i = 0; i < 26; i++){
            if (current->letters[i]){
                wordAfterPrefix.push_back((char)(i + 'a'));
                dfs(current->letters[i], res, wordAfterPrefix);
                wordAfterPrefix.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {          
        vector<vector<string>> ans;
        Trie trie = Trie();
        for (auto& product : products)
            trie.addWord(product);
        string prefix;
        for (auto c : searchWord){
            prefix.push_back(c);
            ans.push_back(trie.wordsBeginWith(prefix));
        }
        return ans;
    }
};