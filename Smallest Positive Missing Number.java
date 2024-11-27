class Solution {
    // Function to find the smallest positive number missing from the array.
    public int missingNumber(int[] arr) {
        // Your code here
        
        Set<Integer> set = new TreeSet<>();
        
        for(int i:arr){
            if(i>0){
                set.add(i);
            }
        }
        
        int n = arr.length;
        for (int i = 1; i <= n; i++) {
            if (!set.contains(i)) {
                return i;
            }
        }
        
        return n + 1;
    }
}
