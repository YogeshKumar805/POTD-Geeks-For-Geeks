class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        vector<int> rows;
        vector<int> cols;

        rows.push_back(0);
        cols.push_back(0);

        for (int i = 0; i < k; i++) {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }

        rows.push_back(n + 1);
        cols.push_back(m + 1);

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0;
        int maxCols = 0;

        for (int i = 1; i < rows.size(); i++) {
            int freeRows = rows[i] - rows[i - 1] - 1;
            maxRows = max(maxRows, freeRows);
        }

        for (int i = 1; i < cols.size(); i++) {
            int freeCols = cols[i] - cols[i - 1] - 1;
            maxCols = max(maxCols, freeCols);
        }

        return maxRows * maxCols;
    }
};
