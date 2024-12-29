class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s(b.begin(), b.end());
        set<int> sa(a.begin(), a.end());
        
        vector<int> v;
        
        for(int i : sa)
            if(s.count(i))
                v.push_back(i);
        
        return v;
        
    }
};
