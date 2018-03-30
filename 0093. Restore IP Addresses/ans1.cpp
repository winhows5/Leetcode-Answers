/* time cost: 3ms (96.89%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isValid (string s) {
        if (s.size() == 0 || s.size() > 3) return false;
        else if (s.size() == 1) return true;
        else 
            if (s[0] == '0') return false;
            else if (s.size() == 3 && (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0') > 255) return false;
            else return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int lng = s.size();
        if (s.size() > 12) return ans;
        for (int i = 1; i < lng-2; ++i)
            for (int j = 1; j < lng-i-1; ++j)
                for (int k = 1; k < lng-i-j; ++k) {
                    if (isValid(s.substr(0, i)) && isValid(s.substr(i, j))
                        && isValid(s.substr(i+j, k)) && isValid(s.substr(i+j+k, lng-i-j-k))) {
                        ans.push_back(s.substr(0, i) + "." + s.substr(i, j) + "." 
                                      + s.substr(i+j, k) + "." + s.substr(i+j+k, lng-i-j-k));
                    }
                }
        return ans;
    }
};
