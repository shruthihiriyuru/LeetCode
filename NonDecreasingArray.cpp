/*
665. Non-decreasing Array
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

Hint:
The strategy is to lower a[i-1] to match a[i] if possible - (a[i-2] not exist or no smaller than a[i]);
otherwise rise a[i] to match a[i-1]
*/


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n < 3) {
            return true;
        }
        int count = 0;
        for (int i=1;i<n;i++) {
             if (nums[i-1] > nums[i]) {
                 count++;
                 if (i-2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                 else
                     nums[i] = nums[i-1];
             }
                 
            
        }
        
        
        return count < 2;
    }
};
