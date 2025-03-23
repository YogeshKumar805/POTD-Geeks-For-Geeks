class Solution {
    public int countWays(String digits) {
        int[] dp = new int[digits.length()];
        Arrays.fill(dp, -1);
        return solve(digits, dp, 0);
    }
    
    private int solve(String digits, int[] dp, int ind) {
        if (ind == digits.length()) return 1;
        if (digits.charAt(ind) == '0') return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int res = solve(digits, dp, ind + 1);
        
        if (ind + 1 < digits.length()) {
            int num = (digits.charAt(ind) - '0') * 10 + (digits.charAt(ind + 1) - '0');
            if (num <= 26) {
                res += solve(digits, dp, ind + 2);
            }
        }
        
        return dp[ind] = res;
    }
}
