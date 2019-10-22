/* time cost: 0ms (100.00%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0; i<32; ++i) {
            res += n & 1;
            n >>= 1;
            if (i==31) break;
            res <<= 1;
        }
        return res;
        
        // whimsy
        // n = ( n>>16 ) | ( n<<16 );   
        // n = ( n>>8 & 0x00ff00ff ) | (n<<8 & 0xff00ff00 );
        // n = ( n>>4 & 0x0f0f0f0f ) | (n<<4 & 0xf0f0f0f0 );
        // n = ( n>>2 & 0x33333333 ) | (n<<2 & 0xcccccccc );
        // n = ( n>>1 & 0x55555555 ) | (n<<1 & 0xaaaaaaaa );
        // return n;
    }
};