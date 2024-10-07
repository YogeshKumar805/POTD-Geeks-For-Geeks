class Solution {
  public:
    int pairsum(vector<int> &arr) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        
        int m1=arr[n-1];
        int m2=arr[n-2];
        
        return m1+m2;
        
    }
};
