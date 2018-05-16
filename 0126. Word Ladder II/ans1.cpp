/* time cost: ms (%) */
/* time complexity: O() */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void resList(string start, string end, unordered_map<string, vector<string>> map_words, 
             vector<string> valid_list, vector<vector<string>> res) {
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
        vector<vector<string>> ans;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());  
        if (wordSet.find(endWord) == wordSet.end()) return ans;
        wordSet.erase(endWord);
        wordSet.erase(startWord);
        unordered_set<string> beginSet, endSet, *pbeginSet, *pendSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        
        unordered_map<string, vector<string>> map_words;
        vector<string> valid_list;
        
        // BFS
        while(!beginSet.empty() && !endSet.empty()) {

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
        
        // DFS
        resList(start, end, map_words, valid_list, res);
        return ans;
    }
};

    
    // remove words on current both ends from the dict
    dict.removeAll(set1);
    dict.removeAll(set2);
    
    // as we only need the shortest paths
    // we use a boolean value help early termination
    boolean done = false;
    
    // set for the next level
    Set<String> set = new HashSet<String>();
    
    // for each string in end 1
    for (String str : set1) {
      for (int i = 0; i < str.length(); i++) {
        char[] chars = str.toCharArray();
        
        // change one character for every position
        for (char ch = 'a'; ch <= 'z'; ch++) {
          chars[i] = ch;
          
          String word = new String(chars);
          
          // make sure we construct the tree in the correct direction
          String key = flip ? word : str;
          String val = flip ? str : word;
              
          List<String> list = map.containsKey(key) ? map.get(key) : new ArrayList<String>();
              
          if (set2.contains(word)) {
            done = true;
            
            list.add(val);
            map.put(key, list);
          } 
          
          if (!done && dict.contains(word)) {
            set.add(word);
            
            list.add(val);
            map.put(key, list);
          }
        }
      }
    }
    
    // early terminate if done is true
    return done || helper(dict, set2, set, map, !flip);
  }
