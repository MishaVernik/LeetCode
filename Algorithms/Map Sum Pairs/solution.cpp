/**
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, pair<int, vector<int>>> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        vector<int> vHash;
        int hash = 0;
        for (auto el : key){
            hash += el - 'a';
            vHash.push_back(hash);
        }  
        mp[key] = {val, vHash};
        //mp.insert({key, {val, vHash}});
    }
    
    int sum(string prefix) {
        int hash = 0;
        bool check = true;
        int sum = 0;
        for (auto el : prefix)
            hash += el - 'a';
        for (auto el : mp){
            if (el.second.second.size() >= prefix.length() && el.second.second[prefix.length()-1] == hash){
                check = true;
                for (int i = 0; i < prefix.length(); i++)
                    if (prefix[i] != el.first[i]){
                        check = false;
                        break;
                    }
                if (check)
                    sum += el.second.first;
            }
        }
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */