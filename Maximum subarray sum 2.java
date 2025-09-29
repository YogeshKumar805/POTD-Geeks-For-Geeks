class Solution {
    public int maxSubarrSum(int[] arr, int a, int b) {
     int n = arr.length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        Deque<Integer> dq = new ArrayDeque<>();
        long ans = Long.MIN_VALUE;

        for (int r = a; r <= n; r++) {
            // Maintain deque: add index (r - a)
            int idx = r - a;
            while (!dq.isEmpty() && prefix[dq.peekLast()] >= prefix[idx]) {
                dq.pollLast();
            }
            dq.addLast(idx);

            // Remove out of range indices (< r - b)
            while (!dq.isEmpty() && dq.peekFirst() < r - b) {
                dq.pollFirst();
            }

            // Compute max subarray sum ending at r-1
            if (!dq.isEmpty()) {
                ans = Math.max(ans, prefix[r] - prefix[dq.peekFirst()]);
            }
        }

        return (int) ans;
    }
}
