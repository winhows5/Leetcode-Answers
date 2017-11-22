/* sort and find */
/* time cost: 6ms (77.45%)*/
/* time complexity: O(nlog(n)) */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    vector<int> newn = nums;
    std::sort(nums.begin(), nums.end());
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
        for (vector<int>::iterator iter2 = nums.end() - 1; iter2 != iter; --iter2){
            if (*iter + *iter2 < target)
                break;
            else if (*iter + *iter2 == target){
                for(vector<int>::iterator it = newn.begin(); it != newn.end(); it++){
                    if (*it == *iter &&
                       (iter >= newn.begin() && iter <= newn.end()) == false) {
                        iter = it;
                        continue;
                    }
                    if (*it == *iter2){
                        iter2 = it;
                    }
                }
                ans.push_back(iter - newn.begin());
                ans.push_back(iter2 - newn.begin());
                return ans;
            }
                
        }
    }
    }
};
