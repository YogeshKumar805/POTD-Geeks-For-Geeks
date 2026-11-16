class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int ans = k;
        for(int &n : arr) {
            if(n <= ans) ans++;
        }
        
        return ans;
    }
};
