class Solve {
    int[] findTwoElement(int arr[]) {
        // code here
         int n=arr.length;
        Arrays.sort(arr);
        int two[]=new int[n+1];
        int ans[]=new int[2];
        for(int i=0;i<n;i++){
        two[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
        if(two[i]>1){
        ans[0]=i;
            }
        if(two[i]==0){
        ans[1]=i;
            }
        }
        return ans;
    }
}
