#include <vector>
#include <numeric>
#define vi std::vector<int>
#define vvi std::vector<vi>
#define ll long long int

class Solution {
public:
    const int mod = 1e9+7;
    
    // Recursive helper function for memoization (Not used in final solution)
    ll help(int idx, int tar, int sum, int n, vi &arr) {
        if (idx == n) {
            return sum == tar;
        }
        
        ll pick = help(idx+1, tar+arr[idx], sum, n, arr) % mod;
        ll notpick = help(idx+1, tar, sum, n, arr) % mod;
        
        return (pick + notpick) % mod;
    }
    
    int countPartitions(int n, int d, vi& arr) {
        // Calculate the total sum of the array
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        
        // If the total sum is less than the given difference or if the target sum is not an integer
        if (sum < d || (sum - d) % 2 != 0) return 0;
        
        // Calculate the required subset sum
        int req = (sum - d) / 2;
        
        // Initialize DP table
        vvi dp(n+1, vi(req+1, 0));
        dp[n][0] = 1;  // Base case: there's one way to get sum 0 with no elements
        
        // Populate the DP table
        for (int idx = n-1; idx >= 0; --idx) {
            for (int tar = 0; tar <= req; ++tar) {
                ll notpick = dp[idx+1][tar] % mod;
                ll pick = (tar >= arr[idx]) ? dp[idx+1][tar-arr[idx]] % mod : 0;
                
                dp[idx][tar] = (pick + notpick) % mod;
            }
        }
        
        return dp[0][req];
    }
};
