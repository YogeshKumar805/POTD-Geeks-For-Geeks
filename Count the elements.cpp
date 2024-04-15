class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        sort(b.begin(), b.end());
        vector<int> ans(q);
        
        for(int i = 0; i < q; ++i) {
            int val = a[query[i]];
            int upper = upper_bound(b.begin(), b.end(), val) - b.begin();
            ans[i] = upper;
        }
        
        return ans;
    }
};
