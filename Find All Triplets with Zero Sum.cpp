class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int sum = arr[i] + arr[j];
                int remain = 0 - sum;
                if(mp.find(remain) != mp.end()) {
                    auto curr = mp[remain];
                    int idx = lower_bound(curr.begin(), curr.end(), j + 1) - curr.begin();
                    for(int k = idx; k < curr.size(); k++) ans.push_back({i, j, curr[k]});
                }
            }
        }
        return ans;
    }
};
