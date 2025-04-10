class Solution {

    // Helper method to calculate Manhattan distance
    private int manhattanDist(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }

    public int minCost(int[][] houses) {
        int n = houses.length;
        boolean[] inMST = new boolean[n]; // Track nodes in MST
        int[] minDist = new int[n];       // Minimum edge cost to MST
        Arrays.fill(minDist, Integer.MAX_VALUE);

        int totalCost = 0;

        // Min-heap to pick the node with the smallest connection cost
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0}); // {cost, index}

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int cost = top[0];
            int u = top[1];

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = manhattanDist(houses[u], houses[v]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.offer(new int[]{dist, v});
                    }
                }
            }
        }

        return totalCost;
    }
}
