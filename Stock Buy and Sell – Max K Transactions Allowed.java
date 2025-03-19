class Solution {
    
    static int f(int ind, int buy, int arr[], int k, int dp[][][]){
        if(k<0)return 0;
        if(ind==arr.length)return 0;
        
        if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];
        
        int profit=0;
        if(buy==1){
            profit=Math.max(-arr[ind]+f(ind+1, 0,arr, k-1,dp), f(ind+1, 1, arr, k,dp));
        }else {
            profit=Math.max(arr[ind]+f(ind+1, 1,arr, k,dp), f(ind+1, 0, arr, k,dp));
        }
        
        return dp[ind][buy][k]=profit;
    }
    
    
    
    static int maxProfit(int arr[], int k) {
        int dp[][][]=new int[arr.length][2][k+1];
        for(int a[][]: dp){
            for(int b[]: a){
                Arrays.fill(b,-1);
            }
        }
        return f(0, 1, arr, k,dp);
        
    }
}
