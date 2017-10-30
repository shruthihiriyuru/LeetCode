class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];
        if (n==2)
            return max(nums[0], nums[1]);
        int rob = 0;
        int notrob = 0;
        
        /*Consider first one as robbed */
        for (int i=2;i<n-1;i++) {
            int currob = notrob + nums[i];
            notrob = max(notrob, rob);
            rob = currob;
        }
        
        int a = max(rob, notrob) + nums[0];
        rob = 0, notrob = 0;
        /* Consider first one as notrobbed */
        for (int i=1;i<n;i++) {
            int currob = notrob + nums[i];
            notrob = max(notrob, rob);
            rob = currob;
        }
        
        int b = max(rob, notrob);
        
        return max(a, b);
        
    }
};
