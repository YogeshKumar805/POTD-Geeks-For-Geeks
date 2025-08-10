class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ct = 0;
        for(int i=0;i<s.size();i++){
            for(int j=1;i-j>=0 && i+j < s.size(); j++){
                if(s[i-j]!=s[i+j]) break;
                ct++;
            }
            for(int j=1;i-j+1>=0 && i+j < s.size(); j++){
                if(s[i-j+1]!=s[i+j]) break;
                ct++;
            }
        }
        return ct;
    }
};
