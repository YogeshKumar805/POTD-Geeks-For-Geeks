class Solution {
  public:
    virtual int kthMissing(vector<int> &arr, int k){
      int n = arr.size();
      int low=1, high=arr[n-1]+k; 
      
      while(low < high){
        int m = low + (high-low)/2;
        
        int miss = m - (upper_bound(arr.begin(), arr.end(), m) - arr.begin());
        
        if(miss >= k)
          high = m;
        else
          low = m+1;
        
      }
      
      return low;
    }
};
