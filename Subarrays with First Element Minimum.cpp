class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n,n);
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            if(st.empty())nse[i]=n;
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt+=(nse[i]-i);
        }
        return cnt;
    }
};

