class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> v;
        for (int i=0;i<a.size();i++){
            v.push_back(a[i]);
        }
        for (int i=0;i<b.size();i++){
            v.push_back(b[i]);
        }
        set<int> st(v.begin(),v.end());
        return (st.size());
    }
};
