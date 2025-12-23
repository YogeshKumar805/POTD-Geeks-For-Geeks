class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(begin(arr), end(arr));
        vector<int> ans;
        
        for (auto& q : queries) {
            
            int a = q[0];
            int b = q[1];
            
            int l = lower_bound(begin(arr), end(arr), a) - arr.begin();
            int r = upper_bound(begin(arr), end(arr), b) - arr.begin();
            
            ans.push_back(r - l);
        }
        
        return ans;
    }
};
