class Solution {
  public:
    string longestString(vector<string> &words) {
        int n = (int)words.size(), maxLen = 0;
        string res = "";
        unordered_map<string, bool> mp;
        for(string word : words) mp[word] = true;
        for(string word : words) {
            string temp = "";
            bool no = false;
            for(char ch : word) {
                temp += ch;
                if(!mp[temp]) {
                    no = true;;
                    break;
                }
            }
            if(!no && maxLen <= (int)word.length()) {
                if(maxLen == (int)word.length()) {
                    res = min(res, word);
                } else {
                    res = word;
                }
                maxLen = (int)word.length();
            }
        }
        return res;
    }
};
