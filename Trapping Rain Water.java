class Solution {
    public int maxWater(int arr[]) {
        // code here
        int n = arr.length;
        int pre[] = new int[n];
        int post[] = new int[n];
        pre[0] = arr[0];
        int ans = 0;
        post[n-1] = arr[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = Math.max(pre[i-1],arr[i]);
            
        }
        for(int j = n-2; j >= 0; j--){
            post[j] = Math.max(post[j+1],arr[j]);
        }
        
        for(int i = 0; i < n; i++){
            ans += Math.min(pre[i],post[i]) - arr[i];
        }
        return ans;
    }
}

