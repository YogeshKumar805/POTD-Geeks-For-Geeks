class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
       
       unordered_map<int,int> map;
       stack<pair<int,int>> st;
       int n = arr.size();
       vector<int> ans(n,-1);
       
       for(int& val : arr){
           map[val]++;
       }
       
       for(int i=n-1; i>=0; i--){
           
           while(!st.empty() && st.top().first <= map[arr[i]]){
               st.pop();
           }
           if(!st.empty()){
               ans[i] = st.top().second;
           }
           st.push({map[arr[i]],arr[i]});
       }
       
       return ans;
    }
};
