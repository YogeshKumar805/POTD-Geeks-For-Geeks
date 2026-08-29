class Solution {
public:
    inline static int mod = 1000000007;
    int countSubsequences(string& s, int n) {
        //let's directly do the bottom-up DP.
        vector<vector<int>> dp(s.length(),vector<int>(n+1,0));
        int cnt = 0;
        if((s[0]-'0')%n == 0){
            cnt++;
        }
        int a = (s[0]-'0')*10;
        a = a%n;
        for(int i = 0;i<dp[0].size();i++){
            if(i == a){
                dp[0][i] += 1;
                continue;
            }
        }
        for(int i = 1;i<dp.size();i++){
            int u = (s[i]-'0')%n;
            if(u == 0){
                cnt++;
                cnt = (cnt + dp[i-1][0])%mod;
            }
            else{
                cnt = (cnt + dp[i-1][n-u])%mod;
            }
        for(int j = 0;j<dp[0].size();j++){
            int a = (s[i]-'0')%n;
            int b = dp[i-1][j];
            
            dp[i][j] = (dp[i][j] + b)%mod;
            if(b > 0){
                int c = (a+j)%n;
                c = c*10;
                
                dp[i][c%n] = (dp[i][c%n] + b)%mod;
            }
        }
            int d = ((s[i]-'0')*10)%n;
            dp[i][d] = (dp[i][d] + 1)%mod;
        }
        return cnt;
    }
};

