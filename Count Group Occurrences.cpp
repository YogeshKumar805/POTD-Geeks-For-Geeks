class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        vector<int>arr(26,0);
        arr[s[0]-'a']=1;
        int n = s.size();
        int ans = 0;
        for(int i=1;i<n;i++) if(s[i]!=s[i-1])arr[s[i]-'a']++;
        for(int i=0;i<26;i++)if(arr[i]==k)ans++;
        return ans;
        
    }
};
