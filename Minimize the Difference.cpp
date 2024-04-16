class Solution {
public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> post_max(n), post_min(n);
        post_max[n - 1] = post_min[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            post_max[i] = max(arr[i], post_max[i + 1]);
            post_min[i] = min(arr[i], post_min[i + 1]);
        }
        int mini = arr[0], maxi = arr[0], res = post_max[k] - post_min[k];
        for(int i = 1; i < n - k; i++) {
            res = min(res, max(maxi, post_max[i + k]) - min(mini, post_min[i + k]));
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        res = min(res, maxi - mini);
        return res;
    }
};
