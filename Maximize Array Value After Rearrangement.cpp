class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        int mod = 1e9 + 7;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            sum =(sum + (long)i*arr[i])%mod;
        }
        return sum;
    }
};
