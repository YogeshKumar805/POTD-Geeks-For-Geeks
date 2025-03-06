class Solution {
    private static int[][] dp;
    private static int LCS(int i,int j,String s1,String s2){
        if(i==s1.length() || j==s2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j)) return dp[i][j]=1+LCS(i+1,j+1,s1,s2);
        else return dp[i][j]=Math.max(LCS(i+1,j,s1,s2),LCS(i,j+1,s1,s2));
    }
    static int lcs(String s1, String s2) {
        int m=s1.length();
        int n=s2.length();
        dp=new int[m][n];
        for(int[] row:dp) Arrays.fill(row,-1);
        return LCS(0,0,s1,s2);
        
    }
}
