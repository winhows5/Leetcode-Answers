/* time cost: 13ms (100.00%) */
/* time complexity: O(nm)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        int i, wSize = words.size(), 
            wL = words[0].size(), 
            start, cur, 
            sL = s.size(), wCnt;
        vector<int> res;
        if(sL < wL*wSize) return res;
        
        for(i = 0; i < wSize; ++i)
            map[words[i]] = map.count(words[i])>0? ++map[words[i]]:1;
        
        for(i = 0; i < wL; ++i) { 
            start = cur = i; 
            wCnt = wSize; 
            while (start <= sL - wL*wSize) {
                if (map.count(s.substr(cur, wL)) == 0){
                    wCnt = wSize;
                    for (; start != cur; start += wL) 
                        ++map[s.substr(start,wL)];
                    start += wL; 
                }
                else if (map[s.substr(cur, wL)] == 0){
                    for (; s.substr(cur,wL) != s.substr(start,wL); start+=wL) {
                        ++map[s.substr(start,wL)];
                        ++wCnt;
                    }
                    start += wL;
                }
                else {
                    --map[s.substr(cur,wL)]; 
                    if(--wCnt == 0) {
                        res.push_back(start); 
                        ++map[s.substr(start,wL)]; 
                        start += wL;
                        ++wCnt;
                    }
                }
                cur += wL; 
            }
            for (; start<cur; start+=wL)  ++map[s.substr(start,wL)]; 
        }
        return res;
    }
        
};
