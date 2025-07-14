class Solution {
  public:
    bool valid(int n){
        while(n > 1){
            if(n%5 != 0)return false;
            n/=5;
        }
        return (n==1);
    }
    int solve(string& s,int curr){
        if(curr < 0){
            return 0;
        }
        int val = 0;
        int ans = INT_MAX;
        for(int i=curr;i>=0;i--){
            val += (s[i]-'0')*pow(2,curr-i);
            if(valid(val)){
                int br = solve(s,i-1);
                if(br < 0 || s[i]=='0')continue;
                ans = min(ans,1 + br);
            }
            else{
                continue;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
    int cuts(string s) {
        int n = s.size();
        return solve(s,n-1);
    }
};
