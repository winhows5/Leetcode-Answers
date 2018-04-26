/* time cost: 175ms (47.68%)    */
/* time complexity: O(knlog(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 1;
        unordered_set<string> markList, findList(wordList.begin(), wordList.end());  
        if (findList.find(endWord) == findList.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            ++cnt;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string tmp = q.front();
                q.pop();
                for (int j = 0; j < tmp.size(); ++j) {
                    char tmp_c = tmp[j];
                    for (int k = 0; k < 26; ++k) {
                        tmp[j] = 'a' + k;
                        if (tmp[j] != tmp_c && markList.find(tmp) == markList.end() &&
                            findList.find(tmp) != findList.end()) {
                            if (tmp == endWord) return cnt;
                            q.push(tmp);
                            markList.insert(tmp);
                            findList.erase(tmp);
                        }
                    }
                    tmp[j] = tmp_c;
                }
            }
        }
        return 0;
    }
};
