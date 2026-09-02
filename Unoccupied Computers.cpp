class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_set<char>st, st1;
        int cnt = 0;
        for(auto it : s){
            if(st.find(it) != st.end()){
                st.erase(it);
                continue;
            }
            if(st.size() == n){
                st1.insert(it);
                continue;
            }
            if(st1.find(it)!=st1.end())continue;
            st.insert(it);
        }
        return st1.size();
    }
};
