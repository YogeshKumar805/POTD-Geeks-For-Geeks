class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> same(n + 1, 0);
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            same[arr[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (same[i] >= 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
