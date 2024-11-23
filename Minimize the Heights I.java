class Solution {
    public int getMinDiff(int k, int[] arr) {
        int n=arr.length;
        Arrays.sort(arr);
        int ans=arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
                int max=Math.max(arr[i-1]+k,arr[n-1]-k);
                int min=Math.min(arr[0]+k,arr[i]-k);
                ans=Math.min(ans,max-min);
        }
        return ans;
    }
}
