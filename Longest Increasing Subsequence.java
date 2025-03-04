class Solution {
    static int lis(int arr[]) {
        int n=arr.length;
        int dp[]=new int[n];
        dp[0]=1;
        int omax=1;
        for(int i=1;i<n;i++){
            int max=dp[i];
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    max=Math.max(max,dp[j]);
                }
            }
            dp[i]=max+1;
            omax=Math.max(omax, dp[i]);
        }
        return omax;
    }
}
