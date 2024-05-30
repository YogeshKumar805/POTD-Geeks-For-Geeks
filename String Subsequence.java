class Solution {
    public static int mod=(int)(1e9+7);
    public static int rec(int i,int j,String s,String t,int dp[][]){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int p=0;
        int np=rec(i-1,j,s,t,dp);
        if(s.charAt(i)==t.charAt(j)) p=rec(i-1,j-1,s,t,dp);
        return dp[i][j]=(p+np)%mod;
    }
    public static int countWays(String s1, String s2) {
        // code here
        int dp[][]=new int[s1.length()][s2.length()];
        for(int[] d:dp) Arrays.fill(d,-1);
        return rec(s1.length()-1,s2.length()-1,s1,s2,dp);
    }
}
