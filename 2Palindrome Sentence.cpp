class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int l = 0, r = s.size();
        while(l<r){
            if(!isalpha(s[l]) && !isdigit(s[l])){
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])){
                r--;
                continue;
            }
            if(isupper(s[l]))s[l] = tolower(s[l]);
            if(isupper(s[r]))s[r] = tolower(s[r]);
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
};

