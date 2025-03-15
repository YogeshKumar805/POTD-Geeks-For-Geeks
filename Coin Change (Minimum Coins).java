class Solution {

    public int minCoins(int coins[], int target) {
        // code here
           // Initialize dp array with a large number (infinity)
        int[] dp = new int[target + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        
        // Base case: 0 coins are needed to form sum 0
        dp[0] = 0;
        
        // Iterate over each coin
        for (int coin : coins) {
            // For each coin, update dp for all sums >= coin
            for (int i = coin; i <= target; i++) {
                if (dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[target] is still Integer.MAX_VALUE, it means we can't form the target sum
        return dp[target] == Integer.MAX_VALUE ? -1 : dp[target];
    
    }
}
