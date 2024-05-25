class Solution {
    long max_Books(int arr[], int n, int k) {
        // Your code here
        long res=0;
        for(int i=0;i<n;i++) {
            long cur=0;
            for(int j=i;j<n;j++) {
                if(arr[j]>k) {
                    i=j;
                    break;
                }
                else cur+=arr[j];
            }
            res=Math.max(res,cur);
        }
        return res;
    }
}
