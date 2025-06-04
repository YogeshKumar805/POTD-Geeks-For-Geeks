class Solution {
  public:
  #define n 101
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        int dp[n][n][n]={};
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                for (int k=0; k<n3;k++){
                    if(s1[i]==s2[j] && s2[j]==s3[k]) 
                        dp[i+1][j+1][k+1]=dp[i][j][k] +1;
                     else
                        dp[i+1][j+1][k+1]=max({dp[i][j+1][k+1],dp[i+1][j][k+1],dp[i+1][j+1][k]});
                }
            }
        }
        return dp[n1][n2][n3];
    }
};
