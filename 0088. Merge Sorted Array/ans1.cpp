/* time cost: 6ms (99.88%) */
/* time complexity: O(m+n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        while(m > 0 && n > 0) {
            if (nums1[m-1] < nums2[n-1]) {
                nums1[m+n-1] = nums2[n-1];
                --n;
            }
            else {
                nums1[m+n-1] = nums1[m-1];
                --m;
            }
        }
        while (n > 0) {
            nums1[n-1] = nums2[n-1];
            --n;
        }
        
    }
};
