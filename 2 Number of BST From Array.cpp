class Solution {
  public:
    virtual vector<int> countBSTs(vector<int>& arr){
      vector<int> ans;
      
      int n=arr.size();
      vector<long long int> cat(n+1, 0);
      cat[0]=cat[1]=1;
      
      vector<int> v=arr;
      sort(v.begin(), v.end());
      
      for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
          cat[i] += (cat[j]*cat[i-1-j]);    
        }  
      }
      
      //--------------
      
      
      for(int i=0; i<n; i++){
        int ind=lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        int l=ind-0;
        int r=n-1-ind;
        
        ans.push_back((int)(cat[l]*cat[r]));
        
      }
      
      return ans;
      
    }
};
