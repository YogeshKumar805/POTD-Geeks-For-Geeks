class Solution {
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    static int findPlatform(int arr[], int dep[]) {
        // add your code here
        Arrays.sort(arr);
        Arrays.sort(dep);

        int n=arr.length;
        int maxplatform=0;
        int platformneeded=0;
        int i=0,j=0;
        while(i<n &&j<n){
            if(arr[i]<=dep[j]){
                platformneeded++;
                i++;
            }else{
                platformneeded--;
                j++;
            }
            
            maxplatform=Math.max(maxplatform,platformneeded);
        }
        return maxplatform;
    }
}
