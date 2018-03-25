/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        vector<string> t;
        int lgh = path.size();
        int i = 0;
        while (i < lgh) {
            if (path[i] == '/') {
                if (i == lgh - 1) break;
                else {
                    if (path[i + 1] == '/') {++i; continue;}
                    if (path[i + 1] == '.') {
                        if (i == lgh - 2) break;
                        if (i + 2 < lgh && path[i + 2] == '/') {++i; continue;}
                        if (i + 2 < lgh && path[i + 2] == '.') {
                            if (i == lgh - 3) {
                                if(!t.empty()) t.pop_back();
                                break;
                            }
                            if (i + 3 < lgh && path[i + 3] == '/') {
                                if (t.empty()) {i += 3; continue;}
                                else {t.pop_back(); i += 3; continue;}
                            }
                        }
                    }             
                }
                
                string val = "/";
                while (i + 1 < lgh && path[i + 1] != '/') {
                    ++i;
                    val += path[i];        
                }
                if (!val.empty()) {
                    if (!t.empty() && val.size() == 1) {++i; continue;}
                    t.push_back(val);
                }
                    
            }
            ++i;
        }
        if (t.empty()) return "/";
        for (int i = 0; i < t.size(); ++i)
            ans += t[i];
        return ans;
    }
};
