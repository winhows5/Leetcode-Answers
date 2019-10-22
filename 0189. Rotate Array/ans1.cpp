/* time cost: 16ms (85.86%) */
/* time complexity: O(n) */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Method1: not concise
        // deque<int> q;
        // for (int n : nums) q.push_back(n);
        // while(k!=0) {
        //     q.push_front(q.back());
        //     q.pop_back();
        //     k--;
        // }
        // for (int i=0; i< nums.size(); ++i) {
        //     nums[i] = q.front();
        //     q.pop_front();
        // }
        
        // Method2: better method with O(1) space 
        // int l = nums.size(); 
        // if (l==0) return;
        // k = k % l;         // reduce
        // if (k!=0) {
        //     for (int i=0; i<gcd(l,k); ++i) {
        //         int cnt = 1;
        //         int temp1 = nums[i],temp2 = nums[i];
        //         int init = cnt*k + i;
        //         do {
        //             temp2 = nums[(cnt*k +i) %l];
        //             nums[(cnt*k +i) %l] = temp1;
        //             temp1 = temp2;
        //             cnt++;
        //         } while ((cnt*k +i) %l != init);
        //     } 
        // }   
            
        // Method3: if use libs
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        
    }
    
    int gcd(int a, int b) {

        while(a!=b) {
            while (a>b) {a=a-b;}
            while (a<b) {b=b-a;}
        }
        return a;
    }
};