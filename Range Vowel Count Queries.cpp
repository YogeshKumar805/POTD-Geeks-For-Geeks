class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
      // code here
      int n = s.size();
      int cntVowels = 0;
      vector<int> vowelsCnt(n, 0);
      vector<int> result;
      unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
      for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (st.find(ch) != st.end())
          cntVowels++;
        vowelsCnt[i] = cntVowels;
      }
      for (auto &query : queries) {
        int l = query[0] - 1, r = query[1];
        int rVowels = vowelsCnt[r];
        int lVowels = 0;
        if (l >= 0)
          lVowels = vowelsCnt[l];
        result.push_back(rVowels - lVowels);
      }
      return result;
    }
};
