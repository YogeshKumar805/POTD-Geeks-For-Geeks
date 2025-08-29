class Solution {
  public:
    string smallestWindow(string &s, string &p) 
    {
        int cnt = 0 , ans = s.size() , idx = -1 , i = 0;
        vector<int>freq(26, 0);
        for(char ch : p)
        {
            if(freq[ch - 'a'] == 0)
                cnt++;
            freq[ch - 'a']++;
        }
        for(int j = 0; j < s.size(); j++)
        {
            char ch = s[j];
            freq[ch - 'a']--;
            if(freq[ch - 'a'] == 0)
                cnt--;
            while(cnt == 0)
            {
                int length = j - i + 1;
                if(length < ans)
                {
                    ans = length;
                    idx = i;
                }
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] > 0)
                    cnt++;
                i++;
            }
        }
        string res;
        if(idx != -1)
            res = s.substr(idx , ans);
        return res;
    }
};class Solution {
  public:
    string smallestWindow(string &s, string &p) 
    {
        int cnt = 0 , ans = s.size() , idx = -1 , i = 0;
        vector<int>freq(26, 0);
        for(char ch : p)
        {
            if(freq[ch - 'a'] == 0)
                cnt++;
            freq[ch - 'a']++;
        }
        for(int j = 0; j < s.size(); j++)
        {
            char ch = s[j];
            freq[ch - 'a']--;
            if(freq[ch - 'a'] == 0)
                cnt--;
            while(cnt == 0)
            {
                int length = j - i + 1;
                if(length < ans)
                {
                    ans = length;.
                    idx = i;
                }
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] > 0)
                    cnt++;
                i++;
            }
        }
        string res;
        if(idx != -1)
            res = s.substr(idx , ans);
        return res;
    }
};
