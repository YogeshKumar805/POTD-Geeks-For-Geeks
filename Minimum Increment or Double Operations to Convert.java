class Solution {
    public int countMinOperations(int arr[]) {
        int incs = 0, maxi = 0;
        
        for (int a: arr) {
            incs += Integer.bitCount(a);
            maxi = Math.max(maxi, a);
        }
        
        return incs + 31 - Integer.numberOfLeadingZeros(maxi);
    }
}
