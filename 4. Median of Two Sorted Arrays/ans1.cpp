/* time cost: 16ms (99.72%) */
/* time complexity: log(min(m, n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size())  nums1.swap(nums2);
    int m = nums1.size(), n = nums2.size();
    int i, j;

    int min = 0, max = m;
    while (min <= max) {
        int i = (min + max) / 2;
        int j = (m + n + 1) / 2 - i;
        if (i < max && nums2[j-1] > nums1[i])
            min = i + 1; 
        else if (i > min && nums1[i-1] > nums2[j]) 
            max = i - 1; 
        else {
            // so hard to control boundary condition...
            int Left;
            if (i == 0) { Left = nums2[j-1]; }
            else if (j == 0) { Left = nums1[i-1]; }
            else { Left = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];}
            if ( (m + n) % 2 == 1 ) { return Left; }
            int Right;
            if (i == m) { Right = nums2[j]; }
            else if (j == n) { Right = nums1[i]; }
            else { Right = nums2[j] > nums1[i] ? nums1[i] : nums2[j];}
            return (Left + Right) / 2.0;
        }
    }
    return 0;
    }
};
