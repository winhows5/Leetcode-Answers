/* time cost: 6ms (99.62%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int S = 0;
        int mS = 0;
        int size = height.size();
        int i = 0, j = size -1;
        while (i < j) {          
            if(height[i] < height[j]){
                S = (j-i) * height[i];
                ++i;
            }
            else{
                S = (j-i) * height[j];
                --j;
            }
            if (mS < S) mS = S;
            
        }
        return mS;
    }
};
