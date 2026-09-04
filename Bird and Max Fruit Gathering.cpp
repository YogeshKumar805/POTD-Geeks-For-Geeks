class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        int k = min(m, n);

        long long windowSum = 0;
        
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        long long ans = windowSum;

        for (int start = 1; start < n; start++) {
            int removed = start - 1;
            
            int added = (start + k - 1) % n;

            windowSum -= arr[removed];
            windowSum += arr[added];

            ans = max(ans, windowSum);
        }

        return (int)ans;
    }
};
