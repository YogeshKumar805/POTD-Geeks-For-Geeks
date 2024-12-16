class Solution {
    public int kthElement(int a[], int b[], int k) {
        // code here
        int i ;
        int n = a.length;
        int m = b.length;
       int[] arr = new int[n+m];
        for( i = 0;i<n;++i) arr[i] = a[i];
        int j = 0;
        for(  ; i<n+m;++i){
            arr[i]=b[j];
            ++j;
        }
        Arrays.sort(arr);
        return arr[k-1];
    }
}
