/* time cost: 4ms (98.13%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lgh = digits.size();
        vector<int> ans;
        int w = 1;
        for (int i = lgh - 1; i >= 0; --i) {
            digits[i] += w;
            if (digits[i] == 10) {
                w = 1;
                digits[i] = 0;
            }
            else w = 0;
        }
        if (w) {
            ans.push_back(1);
            copy(digits.begin(), digits.end(), back_inserter(ans));
            return ans;
        }
        else return digits;

    }
};
