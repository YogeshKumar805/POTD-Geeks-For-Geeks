class Solution {
    public static int[] productExceptSelf(int arr[]) {
        int n = arr.length;
        int left[] = new int[n];
        int right[] = new int[n];
        
         left[0] = arr[0];
         
         for(int i=1; i<n; i++)
         {
            left[i] = arr[i] * left[i-1];
         }
         
        int pro = arr[n-1];
        arr[n-1] = left[n-2];
        
        for(int i=n-2; i>0; i--)
        {
            int temp = arr[i];
            arr[i] = left[i-1] * pro;
            pro *= temp;
        }
        
        arr[0] = pro;
        
        return arr;
    }
}
