class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        string ans = "";
        int n= s.size();
        if((n & (n-1)) == 0){
            k = k/2;
        }
        else{
            k = k*2;
        }
        
        if(k >= n) return "-1";
        
        stack<int> st;
        
        for(auto& i: s){
            while(!st.empty() && k > 0  && st.top() > i){
                st.pop();
                k--;
            }
            st.push(i);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            int x = st.top();
            st.pop();
            ans += x;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
