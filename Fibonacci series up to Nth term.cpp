class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int>arr(n+1);
        arr[0]=0;
        arr[1]=1;
        int mod = 1000000007;
        for(int i=2;i<=n;i++)
        {
            arr[i] = (arr[i-1]+arr[i-2])%mod;
        }
        return arr;
    }
};
