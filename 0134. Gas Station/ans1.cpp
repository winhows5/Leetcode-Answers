/* time cost: 4ms (99.88%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, left_gas = 0;
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            left_gas += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return left_gas < 0 ? -1 : start;    
    }
};
