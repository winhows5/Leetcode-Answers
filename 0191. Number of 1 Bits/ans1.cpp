/* time cost: 0ms (100.00%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
        
    	// int ones = 0;
    	// while(n!=0) {
    	// 	ones = ones + (n & 1);
    	// 	n = n>>1;
    	// }
    	// return ones;
    }
};