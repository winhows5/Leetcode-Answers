/* time cost: 3ms (6.94%) */
/* time complexity: O(n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (int i = 0; i< s.size(); ++i) {
            if (!par.empty() &&
               ((s[i] == '(' && par.top() == ')') ||
                (s[i] == ')' && par.top() == '(') ||
                (s[i] == '[' && par.top() == ']') ||
                (s[i] == ']' && par.top() == '[') ||
                (s[i] == '{' && par.top() == '}') ||
                (s[i] == '}' && par.top() == '{')))
                par.pop();
            else
                par.push(s[i]);
        }
        return par.empty();
    }
};
