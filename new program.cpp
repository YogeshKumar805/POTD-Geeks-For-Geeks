class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxL = 0;
        int sI = 0;

        while (r < n) {
            int mine = *min_element(arr.begin() + l, arr.begin() + r + 1);
            int maxe = *max_element(arr.begin() + l, arr.begin() + r + 1);
            
            if (maxe - mine <= x) {
                if (r - l + 1 > maxL) {
                    maxL = r - l + 1;
                    sI = l;
                }
                r++; 
            } else {
                l++; 
            }
        }
        return vector<int>(arr.begin() + sI, arr.begin() + sI + maxL);
    }
};
