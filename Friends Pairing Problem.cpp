class Solution {
  public:
  long long fact[20]{0};
    int countFriendsPairings(int n) {
        // code here
        fact[0] = 1;
        for(int i = 1 ; i<20 ; i++){
            fact[i] = fact [i-1] * i;
        }
        int ans = 0;
        for(int s = 0 ;s<=n ; s++){
            if((n - s)&1)continue;
            long long res = fact[n];
            res/= fact[s];
            res/= fact[(n-s)/2];
            res/= (1<<(n-s)/2);
            ans+= res;
        }
        return ans;
    }
};
