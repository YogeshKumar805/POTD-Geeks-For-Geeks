class Solution {
    // Function to sort an array of 0s, 1s, and 2s
    public void sort012(ArrayList<Integer> arr) {
        int a[] = new int[arr.size()];
        
        // Copy elements from ArrayList to array
        for (int i = 0; i < arr.size(); i++) {
            a[i] = arr.get(i);
        }
        
        // Sort the array
        Arrays.sort(a);
        
        // Copy sorted elements back to the ArrayList
        for (int i = 0; i < arr.size(); i++) {
            arr.set(i, a[i]);
        }
    }
}

