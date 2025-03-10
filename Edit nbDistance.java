class Solution {
    int[][] dp;

    int solve(String s1, String s2, int i, int j) {
        if (i == s1.length()) return s2.length() - j;  // Insert remaining characters
        if (j == s2.length()) return s1.length() - i;  // Delete remaining characters

        if (dp[i][j] != -1) return dp[i][j];  // DP memoization check

        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);  // No change needed
        } else {
            int insert = 1 + solve(s1, s2, i, j + 1);      // Insert
            int delete = 1 + solve(s1, s2, i + 1, j);      // Delete
            int replace = 1 + solve(s1, s2, i + 1, j + 1); // Correct Replace logic
            return dp[i][j] = Math.min(insert, Math.min(delete, replace));
        }
    }

    public int editDistance(String s1, String s2) {
        dp = new int[s1.length() + 1][s2.length() + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1); 
        }
        return solve(s1, s2, 0, 0);
    }
}
