class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            long long count = 0;

            for (int x : arr) {
                if (x & (1LL << bit)) {
                    count++;
                }
            }

            long long pairs = count * (count - 1) / 2;

            ans += pairs * (1LL << bit);
        }

        return ans;
    }
};
