class Solution {
  public:
    virtual bool checkSum(int i, int x, vector<int> &updatedArr, vector<vector<int>> &dp){
      if(x==0) return 1;
      if(x<0 || i<0) return 0;
      
      if(dp[i][x] != -1) return dp[i][x];
      
      return dp[i][x] = checkSum(i-1, x-updatedArr[i], updatedArr, dp) || checkSum(i-1, x, updatedArr, dp);
      
    }
    
    
    virtual bool isPossible(vector<int>& arr, int s, int x){
      queue<pair<int, int>> q;
      q.push({s, s});
      
      vector<int> updatedArr;
      
      int i=0, n=arr.size();
      while(!q.empty()){
        auto [v, s]=q.front(); q.pop();
        
        if(i<n) {q.push({arr[i]+s, arr[i]+s+s}); i++;}
        
        if(v>x) break;
        updatedArr.push_back(v);
      }
      
      int upn=updatedArr.size();
      vector<vector<int>> dp(upn, vector<int>(x+1, -1));
      return checkSum(upn-1, x, updatedArr, dp);
    }
};
