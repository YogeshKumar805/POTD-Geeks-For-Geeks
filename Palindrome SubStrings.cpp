class Solution {
  public:
   bool ispalindromic(string &s, int i, int j,vector<vector<int>>&t){
      if(i>=j)return true;
      if(t[i][j]!=-1){
          return t[i][j];
      }
      if(i+1==j){
          if(s[i]==s[j]){
           return t[i][j]=true;
          }
      }
      if(s[i]==s[j]){
         return t[i][j]=ispalindromic(s,i+1,j-1,t);
      }
      return t[i][j]= false;
  }
    int countPS(string &s) {
      int n=s.size();
      int len=1, cnt=0;
      vector<vector<int>>t(n+1,vector<int>(n+1,-1));
      for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
              if(ispalindromic(s,i,j,t)){
                 cnt++;
              }
          }
      }
      return cnt;
        
    }
};
