class Solution {
  public:
    virtual int svc(int i, int sum, string &s, vector<vector<int>> &dp){
      if(i>=(s.size())) return 1;
      if(dp[i][sum] != -1) return dp[i][sum];
      
      int res=0;
      int csum=0;
      
      for(int j=i; j<s.size(); j++){
        csum+=s[j]-'0';
        if(csum >= sum) res+=svc(j+1, csum, s, dp);
      }
      
      return dp[i][sum]=res;
    } 
    
    
    virtual int validGroups(string &s){
      int n=s.size();    
      vector<vector<int>> dp(n+1, vector<int> (9*n+1, -1));    
      return svc(0, 0, s, dp);
    }
};

