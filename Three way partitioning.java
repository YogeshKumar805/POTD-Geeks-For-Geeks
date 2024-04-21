class Solution{
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    public void threeWayPartition(int array[], int a, int b)
    {
        // code here 
        int n = array.length;
        int low = 0, mid = 0, high = n - 1;
        
        while (mid <= high) {
            if (array[mid] < a) {
                swap(array, low, mid);
                low++;
                mid++;
            } else if (array[mid] > b) {
                swap(array, mid, high);
                high--;
            } else {
                mid++;
            }
        }
    }
    
    // Function to swap two elements in the array
    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
