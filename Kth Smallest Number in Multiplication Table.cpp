class Solution {
  public:
    #define ll long long
    int kthSmallest(int m, int n, int k) {
        // code here
        ll start = 1, end = m * n, mid, ans;
        while(start <= end){
            mid = start + (end - start) / 2;
            ll cnt = 0;
            for(ll i = 1; i <= n; i++){
                cnt += min((ll)m, mid/i);
            }
            if(cnt >= k){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};
