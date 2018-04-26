/* time cost: 27ms (99.46%)     */
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
        unordered_set<string> wordSet(wordList.begin(), wordList.end());  
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        wordSet.erase(endWord);
        unordered_set<string> beginSet, endSet, *pbeginSet, *pendSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        while(!beginSet.empty() && !endSet.empty()) {
            ++cnt;
            if (beginSet.size() > endSet.size()) {
                pbeginSet = &endSet;
                pendSet = &beginSet;
            }
            else {
                pbeginSet = &beginSet;
                pendSet = &endSet;
            }
            unordered_set<string> tmpSet;
            for (unordered_set<string>::iterator it = pbeginSet->begin(); 
                it != pbeginSet->end(); ++it) {
                string tmp = *it;
                for (int j = 0; j < tmp.size(); ++j) {
                    char tmp_c = tmp[j];
                    for (int k = 0; k < 26; ++k) {
                        tmp[j] = 'a' + k;
                        if (pendSet->find(tmp) != pendSet->end()) return cnt;
                        if (tmp[j] != tmp_c && wordSet.find(tmp) != wordSet.end()) {
                            tmpSet.insert(tmp);
                            wordSet.erase(tmp);
                        }
                    }
                    tmp[j] = tmp_c;
                }
            }
            swap(*pbeginSet, tmpSet);
        }
        return 0;
    }
};
