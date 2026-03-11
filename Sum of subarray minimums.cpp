class Solution {
  public:
    virtual vector<int> getPSE(vector<int> &arr){
      int n=arr.size();
      vector<int> pse(n);
      
      stack<int> st;
      for(int i=0; i<n; i++){
        while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
        
        if(st.empty()) pse[i]=-1;
        else pse[i]=st.top();
        
        st.push(i);
      }
      
      return pse;
    }
    
    virtual vector<int> getNSE(vector<int> &arr){
      int n=arr.size();
      vector<int> nse(n);
      
      stack<int> st;
      for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
        
        if(st.empty()) nse[i]=n;
        else nse[i]=st.top();
        
        st.push(i);
      }
      
      return nse;
    }
    virtual int sumSubMins(vector<int> &arr) {
      vector<int> pse = getPSE(arr);
      vector<int> nse = getNSE(arr);
      
      int mode=1e9+7;
      int ans=0;
      
      int n=arr.size();
      for(int i=0; i<n; i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        
        ans = (ans + (left*right*1LL*arr[i])%mode)%mode;  
      }
      
      return ans;
    }
};

