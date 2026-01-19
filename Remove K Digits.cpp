class Solution {
  public:
    string removeKdig(string &s, int k) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            while(!ans.empty() && k>0 && ans.back()>s[i]){
                ans.pop_back();
                k--;
            }
            ans+=s[i];
        }
        while(k--) ans.pop_back();
        int i=0;
        while(i<n && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i,n-i);
        if(ans.size()==0) return "0";
        return ans;
    }
};

