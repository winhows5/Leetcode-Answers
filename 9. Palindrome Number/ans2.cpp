/* time cost: 46ms (99.81%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false;
    
    int ans = 0;
    int t = x;
    while(t) {
        ans = ans * 10 + t % 10;
        t /= 10;
    }
    return ans == x;
    
}
};
