class Solution {

    // arr: input array
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int[] arr) {
        
        if(arr == null) return 0;
                
        int currmax = arr[0];
        int totalmax = arr[0];
        
        for(int i=1;i<arr.length;i++){
            
            currmax = Math.max(arr[i], currmax+arr[i]);
            totalmax = Math.max(currmax, totalmax);
            
        }
        return totalmax;

    }
}
