class Solution {
public:
    static const long long MOD = 1000000007;

    long long palindromicStrings(int n, int k) {
        long long ans = 0;
        for (int len = 1; len <= n; len++) {
            int need = (len + 1) / 2;
            long long ways = 1;
            for (int i = 0; i < need; i++) {
                ways = (ways * (k - i)) % MOD;
            }
            ans = (ans + ways) % MOD;
        }

        return ans;
    }
};
