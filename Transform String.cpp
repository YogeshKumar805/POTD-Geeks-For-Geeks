class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        vector<int> freq(53, 0);
        
        int n = s1.length();
        int m = s2.length();
        
        if (n != m) {
            return -1;
        }
        
        for (int i = 0; i < n; i++) {
            char ch1 = s1[i];
            char ch2 = s2[i];
            
            if (ch1 >= 'a' && ch1 <= 'z') {
                freq[ch1 - 'a']++;
            } else {
                freq[ch1 - 'A' + 26]++;
            }
            
            if (ch2 >= 'a' && ch2 <= 'z') {
                freq[ch2 - 'a']--;
            } else {
                freq[ch2 - 'A' + 26]--;
            }
        }
        
        for (int i = 0; i < 53; i++) {
            if (freq[i] != 0) return -1;
        }
        
        int i = n-1;
        int j = n-1;
        int ops = 0;
        
        while (i >= 0 && j >= 0) {
            
            if (s1[i] != s2[j]) {
                ops++;
                i--;
            } else {
                i--;
                j--;
            }
        }
        
        return ops;
    }
};
