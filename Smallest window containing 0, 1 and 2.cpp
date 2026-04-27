class Solution {
  public:
    int smallestSubstring(string s) {
        int n=s.length(), minLen=1e9;
        unordered_map<char,int> mp;
        int left=0, right=0;
        while(right<n){
            mp[s[right]]++;
            while(mp.size()==3){
                minLen=min(minLen,right-left+1);
                if(--mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
            right++;
        }
        return minLen==1e9?-1:minLen;
    }
};
