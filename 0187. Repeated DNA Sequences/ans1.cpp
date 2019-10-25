/* time cost: 8ms (99.10%) */
/* time complexity: O(n) */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10) return res; 
        map<string, int> find;
        for (int i=0; i<s.length()-9; ++i) {
            string sub = s.substr(i,10);
            if (find.find(sub) != find.end()) {
                find[sub]++;
            } else {
                find[sub] = 0;
            }
        }
        for (map<string, int>::value_type e : find) {
            if (e.second > 0) res.push_back(e.first);
        }
        return res;
    }

    // Too Slow (164ms)
    // vector<string> findRepeatedDnaSequences(string s) {
    //     vector<string> res;
    //     if (s.length() < 10) return res; 
    //     map<string, int> find;
    //     for (int i=0; i<s.length()-9; ++i) {
    //         string sub = s.substr(i,10);
    //         if (find.find(sub) != find.end()) {
    //             find[sub]++;
    //         } else {
    //             find[sub] = 0;
    //         }
    //     }
    //     for (map<string, int>::value_type e : find) {
    //         if (e.second > 0) res.push_back(e.first);
    //     }
    //     return res;
    // }
};