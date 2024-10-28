class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(auto x : arr) {
            if(umap.count(x) == 0) {
                ans.push_back(x);
                umap[x]++;
            }
        }
        return ans;
    }
};
