class Solution {
  public:
    int findSubString(string& str) {
        // code here
        vector<int>f(26,0);
        int cnt = 0;
        for(char ch:str)
        {
            if(f[ch-'a']==0)
            {
                cnt++;
            }
            f[ch-'a']++;
        }
        int n = str.length();
        int minLen = INT_MAX;
        int tot =0;
        vector<int>freq(26,0);
        int j = 0;
        for(int i =0;i<n;i++)
        {
            freq[str[i]-'a']++;
            if(freq[str[i]-'a']==1)
            {
                tot++;
            }
            while(tot==cnt)
            {
                freq[str[j]-'a']--;
                if(freq[str[j]-'a']==0)
                {
                    tot--;
                }
                minLen = min(minLen,i-j+1);
                j++;
            }
        }
        return minLen;
    }
};

