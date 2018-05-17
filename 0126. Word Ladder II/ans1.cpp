/* time cost: 37ms (97.10%) */
/* time complexity: O(nlog(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void resList(string start, string end, unordered_map<string, vector<string>>& map_words, 
             vector<string>& valid_list, vector<vector<string>>& res) {
        if (start == end) {
            res.push_back(valid_list);
            return;
        }
        if (map_words.find(start) == map_words.end()) return;
        for (string& word : map_words[start]) {
            valid_list.push_back(word);
            resList(word, end, map_words, valid_list, res);
            valid_list.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());  
        if (wordSet.find(endWord) == wordSet.end()) return res;
        wordSet.erase(endWord);
        wordSet.erase(beginWord);
        unordered_set<string> beginSet, endSet, *pbeginSet, *pendSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        
        unordered_map<string, vector<string>> map_words;
        bool done = false;
        bool flip = false;
        
        // BFS
        while(!beginSet.empty() && !endSet.empty()) {
            
            if (beginSet.size() > endSet.size()) {
                pbeginSet = &endSet;
                pendSet = &beginSet;
                flip = true;
            }
            else {
                pbeginSet = &beginSet;
                pendSet = &endSet;
                flip = false;
            }
            
            unordered_set<string> tmpSet;
            for (unordered_set<string>::iterator it = pbeginSet->begin(); 
                it != pbeginSet->end(); ++it) {
                string tmp = *it;
                for (int j = 0; j < tmp.size(); ++j) {
                    char tmp_c = tmp[j];
                    for (int k = 0; k < 26; ++k) {
                        tmp[j] = 'a' + k;
                        string key_word = flip ? tmp : *it;
                        string val_word = flip ? *it : tmp;
                        if (pendSet->find(tmp) != pendSet->end()) {
                            map_words[key_word].push_back(val_word);
                            done = true;
                        }
                        if (!done && tmp[j] != tmp_c && wordSet.find(tmp) != wordSet.end()
                           && pbeginSet->find(tmp) == pbeginSet->end()) {
                            tmpSet.insert(tmp);
                            map_words[key_word].push_back(val_word);
                        }
                    }
                    tmp[j] = tmp_c;
                }
            }
            if (done) break;
            swap(*pbeginSet, tmpSet);
            for (auto it = tmpSet.begin(); it != tmpSet.end(); ++it) {
                wordSet.erase(*it);
            }
        }

        // DFS
        vector<string> valid_list{beginWord};
        resList(beginWord, endWord, map_words, valid_list, res);
        return res;
    }
};
