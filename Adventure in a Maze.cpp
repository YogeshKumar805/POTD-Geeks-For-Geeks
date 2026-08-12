class Solution {
  public:
    using ll = long long;
    ll dp[101][101] , dp2[101][101];
    int mod = 1e9+7;
    ll cal(int i , int j , vector<vector<int>> & mat)
    {
        if(i == mat.size()-1 && j == mat[0].size()-1 )
        return 1;
        if( i>= mat.size() || j >= mat[0].size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        ll ans = 0;
        if(mat[i][j] == 1 || mat[i][j] == 3)
        ans += cal(i , j+1 , mat)%mod;
        if(mat[i][j] == 2 || mat[i][j] == 3)
        ans = (cal(i+1 , j , mat)%mod + ans ) % mod ;
        return dp[i][j] = ans;
    }
     ll cal2(int i , int j , vector<vector<int>> & mat)
    {
        if(i == mat.size()-1 && j == mat[0].size()-1 )
        return mat[i][j];
        if( i>= mat.size() || j >= mat[0].size())
        return -1e9;
        if(dp2[i][j]!=-1)
        return dp2[i][j];
        ll ans = -1e9;
        if(mat[i][j] == 1 || mat[i][j] == 3)
        ans = max(ans , mat[i][j] + cal2(i , j+1 , mat) );
        if(mat[i][j] == 2 || mat[i][j] == 3)
        ans = max(ans , mat[i][j] + cal2(i+1 , j , mat) );
        return dp2[i][j] = ans;
    }
    
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        memset(dp , -1 , sizeof(dp));
        memset(dp2 , -1 , sizeof(dp2));
        ll a = cal2(0 , 0 ,grid);
        return { cal(0 ,0 , grid) , a<=0 ? 0 : a  };
    }
};
