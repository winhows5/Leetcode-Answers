/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */
 
// It refers to Finite State Machine. Although I get AC, I do not comprehend it deeply.

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first_state = 0, second_state = 0;
        for (int& c: nums) {
            first_state = (first_state ^ c) & ~second_state;
            second_state = (second_state ^ c) &~first_state;
        }
        return first_state;
    }
};
