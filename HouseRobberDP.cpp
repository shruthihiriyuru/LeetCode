/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them
is that adjacent houses have security system connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    /* O(n) time with O(1) space */
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if (!n)
            return 0;
        if (n==1)
            return nums[0];

        int a[n];
        
        a[0] = nums[0];
        a[1] = max(nums[0], nums[1]);
        
        int i = 2;
        
        for (;i<n;i++) {
            a[i] = max(a[i-1], nums[i]+a[i-2]);
        }
        
        return a[i-1];
        
    }
    
    /* O(n) time with O(1) space */
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int rob = 0;
        int notrob = 0;
        
        for (int i=0;i<n;i++) {
            int currob = notrob + nums[i];
            notrob = max(notrob, rob);
            rob = currob;
        }
        
        return max(rob, notrob);
        
    }
};
