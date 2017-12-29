/* time cost: 3ms (9.67%) */
/* time complexity: O(n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// It also can be wrote as a recursion algorithm.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(!n) return {};
        vector<string> Ans{"("};
        vector<vector<int>> k{1, {n - 1, 1}};

        while(1) {
            for (int i = 0; i < Ans.size(); ++i) {
                int r = k[i][1];
                if (k.size() > i && k[i][0]) {
                    if (r) {
                        k.push_back({k[i][0] - 1, r + 1});
                        Ans.push_back(Ans[i] + '(');
                    }
                    else {
                        --k[i][0];
                        ++r;
                        Ans[i] += '(';
                    }
                }
                if (k.size() > i && k[i][1]) {
                    Ans[i] += ')';
                    --r;
                }
                k[i][1] = r;
            }
            if (k[0][1] == 0 && k[0][0] == 0) return Ans;
        }
    }
};
