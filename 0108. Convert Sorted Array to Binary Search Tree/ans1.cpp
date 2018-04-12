/* time cost: 12ms (100.00%) */
/* time complexity: O(n)     */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    TreeNode* creatBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(nums[start+(end-start)/2]);
        root->left = creatBST(nums, start, start+(end-start)/2-1);
        root->right = creatBST(nums, start+(end-start)/2+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return creatBST(nums, 0, nums.size()-1);
    }
};
