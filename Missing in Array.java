class Solution {

    // Note that the size of the array is n-1
    int missingNumber(int n, int arr[]) {

        // Your Code Here
        long sum = (n*(n+1))/2;
        
        long summ = 0;
        
        for(int i = 0;i<arr.length;i++) {
            summ+=arr[i];
        }
        
        return (int)(sum - summ);
    }
}
