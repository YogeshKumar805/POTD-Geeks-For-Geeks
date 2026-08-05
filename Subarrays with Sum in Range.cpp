class Solution {
  public:
  long long subarray_sum(vector<int>&arr , int l){
      int sum = 0 ;
      int st = 0;
      long long ans = 0;
      for(int en =0 ; en < arr.size() ; en++){
          sum +=arr[en];
          while(sum > l){
              sum-= arr[st++];
          }
          ans+= (en - st+1);
      }
      return ans;
      
  }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return (int)(subarray_sum(arr , r) - subarray_sum(arr , l-1));
    }
};
