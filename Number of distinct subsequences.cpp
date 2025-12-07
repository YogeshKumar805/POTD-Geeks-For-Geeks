class Solution {
public:
    static const int MOD = 1000000007;

    int distinctSubseq(string str) {
        int n = str.length();
        vector<long long> dp(n + 1);
        dp[0] = 1; 

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int ch = str[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % MOD;

            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + MOD) % MOD;
            }

            last[ch] = i - 1;
        }

        return dp[n];
    }
};

 
