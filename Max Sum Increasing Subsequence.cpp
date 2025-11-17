class Solution {
public:
    int maxSumIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = nums[i];
        }

        for(int curr = 0; curr < n; curr++){
            for(int prev = 0; prev < curr; prev++){
                if(nums[curr] > nums[prev]){
                    dp[curr] = max(dp[curr], nums[curr] + dp[prev]);
                }
            }
        }

        int maxSum = 0;
        for(int k = 0; k < n; k++){
            maxSum = max(maxSum, dp[k]);
        }

        return maxSum;
    }
};
