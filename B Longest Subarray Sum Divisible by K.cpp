class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int currSum = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            int rem = currSum % k;
            if (rem < 0) rem += k;
            
            if (mp.find(rem) == mp.end()) {
                mp[rem] = i;    
            } else {
                ans = max(ans, i - mp[rem]);
            }
        }
        return ans;
    }
};
