/*
152. Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int curMax = nums[0], curMin = nums[0], res = nums[0];
        for (int i=1;i<n;i++) {
            if (nums[i] > 0) {
                curMax = max(curMax*nums[i], nums[i]);
                curMin = min(curMin*nums[i], nums[i]);
            }
            else {
                int tempMax = curMax;
                curMax = max(curMin*nums[i], nums[i]);
                curMin = min(tempMax*nums[i], nums[i]);
            }
            res = max(res, curMax);
        }
        
        return res;
    }
};
