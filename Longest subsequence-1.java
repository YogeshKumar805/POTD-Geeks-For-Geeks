class Solution {
    public static int longestSubseq(int n, int[] a) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxi = 0;
        for(int i=0;i<n;i++){
            int element = a[i];
            int prev = map.getOrDefault(element-1, 0);
            int next = map.getOrDefault(element+1, 0);
            int crr = Math.max(prev, next) + 1;
            map.put(element, crr);
            maxi = Math.max(maxi, crr);
        }
        return maxi;
    }
}
