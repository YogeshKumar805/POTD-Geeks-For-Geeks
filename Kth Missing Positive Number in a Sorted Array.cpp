class Solution {
  public:
  int binarySearch(vector<int>&arr,int k){
      int low = 0;
      int high = arr.size()-1;
      int ans = -1;
      while(low<=high){
        int mid = low+(high-low)/2;
        if((arr[mid]-(mid+1))<k){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
      }
      return ans;
  }
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int start = binarySearch(arr,k);
        if(start==-1){
            return k;
        }
        k= k-(arr[start]-(start+1));
        return arr[start]+k;
    }
};
