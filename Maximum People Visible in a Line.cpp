class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        
        map<int, vector<int>> mp;
        
        int mx = -1;
        for(int i=0; i<n; i++) 
            mp[arr[i]].push_back(i), mx = max(mx, arr[i]);
        
        mp[mx].push_back(-1);
        mp[mx].push_back(n);
        
        sort(mp[mx].begin(), mp[mx].end());
        
        int ans = -1;
        if(mp[mx].size() == 1) {
            return n;
        } else if(mp[mx].size() == 2) {
            return abs(mp[mx][1]-mp[mx][0]) + max(mp[mx][0], n - mp[mx][1] - 1);
        } else {
            for(int i=1; i<mp[mx].size()-1; i++) {
                ans = max(ans, mp[mx][i+1]-mp[mx][i-1] - 1);
            }
        }
        
        return ans;
    }
};
 
