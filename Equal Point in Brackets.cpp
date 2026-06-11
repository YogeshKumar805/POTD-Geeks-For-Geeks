class Solution {
  public:
    int findIndex(string &s) {
        // code here
        return count(s.begin(), s.end(), ')');
    }
};
