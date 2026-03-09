class Solution {
  public:
    string largestSwap(string &s) {
        vector<int>freq(10);
        for(auto i=0;i<s.size();i++) freq[s[i]-'0'] = i;
        
        for(int i=0;i<s.size();i++)
        {
            for(int j=9;(int)(s[i]-'0')<j;j--)
            {
                if(freq[j]>i)
                {
                    swap(s[i],s[freq[j]]);
                    return s;
                }
            }
        }
        
        return s;
    }
};
