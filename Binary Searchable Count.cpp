class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int count = 0;
        int n = (int)arr.size();

        function<void(int, int, long long, long long)> dfs =
            [&](int l, int r, long long low, long long high) {
                if (l > r) return;

                int mid = l + (r - l) / 2;
                long long val = arr[mid];

                if (val > low && val < high) {
                    count++;
                }

                dfs(l, mid - 1, low, min(high, val));

                dfs(mid + 1, r, max(low, val), high);
            };

        dfs(0, n - 1, -(1LL << 60), (1LL << 60));

        return count;
    }
};
