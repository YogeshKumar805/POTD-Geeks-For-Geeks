class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int arr[26];
        for(int i=0 ; i<26 ; i++)arr[i] = -1;
        int ans = -1;
        for(int i = 0 ;i < s.size() ; i++){
            if(s[i]!='a'){
                if(arr[s[i]-'a' -1] !=-1)arr[s[i]-'a'] = (arr[s[i] -'a'] ==-1)? arr[s[i] -'a' - 1]: min(arr[s[i]-'a'] , arr[s[i] -'a' - 1]);
                if(arr[s[i]-'a']>=0)ans = max(ans , i - arr[s[i]-'a']);
            }else{ 
                if(arr[s[i] -'a'] == -1)arr[s[i]-'a'] = i;
                ans = max(0 , ans);
            }
        }
        return ans;
    }
};
