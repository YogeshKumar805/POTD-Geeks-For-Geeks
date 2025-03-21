class Solution {
    int f(int ind, int arr[],int dp[]){
        if(ind<0)  return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        int nt=f(ind-1, arr,dp);
        int t=arr[ind]+f(ind-2, arr,dp);
        return dp[ind]=Math.max(nt, t);
    }
    
    public int findMaxSum(int arr[]) {
        int dp[]=new int[arr.length];
        Arrays.fill(dp,-1);
        return f(arr.length-1, arr,dp);
        
    }
}
