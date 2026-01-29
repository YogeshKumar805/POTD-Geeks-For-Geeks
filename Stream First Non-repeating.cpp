class Solution {
  public:
    virtual string firstNonRepeating(string &s) {
      queue<char> q;
      unordered_map<char, int> freq;
      
      string ans;
      
      for(char &ch: s){
        q.push(ch);
        freq[ch]++;
        
        while(!q.empty() && freq[q.front()]>1) q.pop();
        
        char ach = q.empty()? '#': q.front();
        ans.push_back(ach);
      }
      
      return ans;
    }
};

