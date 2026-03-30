class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();

        vector<int> minDist(n, INT_MAX);

        vector<bool> visited(n, false);

        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; i++) {

            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) +
                               abs(houses[u][1] - houses[v][1]);

                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};
