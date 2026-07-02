class Solution {
  public:
    virtual bool divisibleByK(vector<int>& arr, int k){
      int n=arr.size();
      if(n>=k) return true;
      
      vector<bool> dp(k, false);
      
      for(int i=0; i<n; i++){
        int rem = (arr[i]%k + k)%k;
        if(rem==0) return true;
        
        vector<int> new_rems;
        
        for(int r=1; r<k; r++){
          if(dp[r]){
            int xr = (r+rem)%k;
            if(xr==0) return true;
            
            new_rems.push_back(xr);
          }    
        }
        
        
        for(int x: new_rems) dp[x]=true;
        dp[rem]=true;
        
      }
      
      
      return false;
    }
};
